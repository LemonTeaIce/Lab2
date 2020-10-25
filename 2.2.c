#include <stdlib.h> /*needed to define exit*/
#include <unistd.h> /*needed for fork() and getpid()*/
#include <stdio.h> /*needed for printf()*/
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int pid;//process ID

	switch(pid = fork())
	{
		case 0: //a fork return 0 to child
		printf("i am the child process: pid=%d\n", getpid());
		break;

		default: //a fork return a pid to the parent
		wait(NULL);
		printf("I am the parent process: pid=%d, child pid=%d\n",getpid(),pid);
		break;

		case -1: //something went wrong
		perror("fork");
		exit(1);
	}
	exit(0);
		
}
