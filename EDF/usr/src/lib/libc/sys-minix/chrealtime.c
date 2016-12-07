#include <lib.h>
#include <unistd.h>
#include <stdio.h>

int chrealtime( long deadline)
{
	printf("chrealtime in libc is called \n");
      message m;
      m.m2_l1 = deadline;
      alarm((unsigned int) deadline);
      return(_syscall(PM_PROC_NR, CHREALTIME, &m));
}
