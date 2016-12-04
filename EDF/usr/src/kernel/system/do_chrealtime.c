/* The kernel call implemented in this file:
 *   m_type:	SYS_CHREALTIME
 *
 * The parameters for this kernel call are:
 *    m2_i1:	RA_PROC_NR   indecates a process
 *    m2_l1:	RA_DEADLINE  deadline
 */
#include "kernel/system.h"
#include <stdio.h>
#include <signal.h>

#if USE_CHREALTIME

/*===============================================================*
 *				  do_chrealtime				     *
*===============================================================*/

void reach_deadline(timer_t * tp)
{
  printf("Process %d reaches deadline.\n",tp->tmr_arg.ta_int);
  cause_sig(tp->tmr_arg.ta_int,SIGTERM);
  return;
}
int do_chrealtime(message *m_ptr)
{
  struct proc *rp;
  timer_t *tp;
  rp = proc_addr(m_ptr->m2_i1); //m2_i1 is the end point, proc_addr is in kernel/proc.h
  RTS_SET(rp, RTS_SYS_LOCK);//lock the process from schduled
  if (rp->p_deadline.tmr_exp_time!=0)
  {
    reset_timer(&rp->p_deadline);
    rp->p_deadline.tmr_exp_time = 0;
  }
  if (m_ptr->m2_l1!=0)//if deadline is set
  {
  	tp = &rp->p_deadline;
  	tp->tmr_arg.ta_int = rp->p_nr;
  	tp->tmr_exp_time = m_ptr->m2_l1*60+get_uptime();                                                    // timeout time = duration + the current clock uptime in ticks.
  	tp->tmr_func = reach_deadline;                                                                      //function to terminate time out process
  	printf("Process %d sets timer, deadline = %d \n",tp->tmr_arg.ta_int,tp->tmr_exp_time);
  	set_timer(tp,tp->tmr_exp_time,tp->tmr_func);                                                        //clock.c, set a timer for the time out of process
  }
	RTS_UNSET(rp, RTS_SYS_LOCK);//unlock the process, it can be scheduled
  return(OK);
}
void reach_deadline(timer_t *tp)


#endif /* USE_CHREALTIME */
