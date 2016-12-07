#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <signal.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <lib.h>

int main ()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		printf("child change deadline\n");
		chrealtime(4);
	}
	else
		printf("this is father. almost end.\n");

	for(int count = 0; count < 10; count++) 
	{ 	
       printf("%d:%d\n", pid, count); 
		for(int f = 0; f < 2000; f += 0.001); 
	} 
	return 0;
}