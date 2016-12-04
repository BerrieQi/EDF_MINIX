#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <signal.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <lib.h> 
void child(char name); 
int main(void) 
{ 
	float a;
	int seconds, i; 
	char name; 
	name = 'A'; 
	for(i = 0; i< 4; i++) 
	{ 
		if(fork() == 0) 
		{ 
			child(name); 
		} 
		name++; 
	} 
	printf("father end\n"); 
	exit(0); 
} 
void child(char name) 
{ 
	float f; 
	int count; 
	switch(name) 
	{ 
		case 'A': if(chrealtime(2) != 0) { perror("chrealtime"); exit(1); } break; 
		case 'B': if(chrealtime(3) != 0) { perror("chrealtime"); exit(1); } break; 
       case 'C': if(chrealtime(0) != 0) { perror("chrealtime"); exit(1); } break; 
	} 
	for(count = 0; count < 10; count++) 
	{ 
       /*if (name=='A' && count == 2) chrealtime(0);*/
       /*if (name=='A' && count == 2) chrealtime(3);*/		
       printf("%c:%d\n", name, count); 
		for(f = 0; f < 2000; f += 0.001); 
	} 
	printf("%c end\n", name); 
	exit(0); 
}
