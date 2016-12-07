#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <signal.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <lib.h> 

int main() 
{ 
	char name; 
	name = 'A';
	for( int i = 0; i< 4; i++) 
	{ 
		if(fork() == 0) 
		{ 
			switch(name) 
			{ 
				case 'A': 
					if(chrealtime(2) != 0) 
						{ 
							perror("chrealtime"); 
							exit(1); 
						} 
					break; 
				case 'B': 
					if(chrealtime(4) != 0) 
						{ 
							perror("chrealtime"); 
							exit(1); 
						} 
					break; 
		       	case 'C': 
		       		if(chrealtime(0) != 0) 
		       			{ 
		       				perror("chrealtime"); 
		       				exit(1); 
		       			} 
		       		break; 
			} 
			for(int count = 0; count < 5; count++) 
				{
			       printf(" %c:%d\t", name, count); 
					for(float f = 0; f < 2000; f += 0.0001); 
				} 
				printf("\n%c ends.\n", name); 
				exit(0); 
		} 
		name++; 
	} 
	printf("father ends.\n"); 
	exit(0); 
} 
