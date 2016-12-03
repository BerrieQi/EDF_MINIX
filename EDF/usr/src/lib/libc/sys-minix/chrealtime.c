#include <lib.h>
#include <unistd.h>

int chrealtime( long deadline)
{
      message m;
      m.m2_l1 = deadline;
      alarm((unsigned int) deadline);
      return(_syscall(MM, CHRT, &m));
}
