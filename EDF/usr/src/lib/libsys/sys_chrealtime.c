#include "syslib.h"
#include <stdio.h>

int sys_chrealtime(endpoint_t proc_ep,long deadline)
{
	printf("sys_chrealtime is called in libsys\n");
    message m;
    m.m2_i1 = proc_ep;
    m.m2_l1 = deadline;
    return(_kernel_call(SYS_CHREALTIME, &m));
}
