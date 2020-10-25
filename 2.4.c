#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
	char name[30];
	printf("Enter name:");
	scanf("%s",&name);
	printf("Child name: %s",name);
	return 0;
}

void parentTask()
{
	
	printf("waiting for child process to finish....\n");
	wait(NULL);
	printf("Job is done.\n");
}


int main(void)
{
	pid_t pid = fork();
	for(int i=0; i<4; i++)
	{
 		if(pid == 0)
		{
			childTask();
			exit(EXIT_SUCCESS);
		}

		else if(pid > 0)
		{
			wait(NULL);
			parentTask();
		}
		
		else
		{
			printf("Unable to create child process");
		}

	}
	return EXIT_SUCCESS;
}
