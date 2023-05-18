#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

char	buf[1024];
int		tmp = 0;
bool	turn = false; // false = child
pid_t	parent_pid;

void	child_do()
{
	int i = 0;
	do
	{
		while (turn != 0)
			pause();

		// critical section
		printf("child start\n");

		FILE* pFile = fopen("a.txt", "w+");
		fgets(buf, sizeof(buf), pFile);
		tmp = atoi(buf);
		tmp = tmp + 1;
		rewind(pFile);
		fprintf(pFile, "%d", tmp);
		fclose(pFile);
		i++;
		printf("child do : %d\n", tmp);
		kill(parent_pid, SIGUSR1);
	}
	while (i < 3) ;
}

void	parent_do()
{
	int	i = 0;
	do
	{
		while (turn != 1)
			pause();
		// critical section
		printf("parent start\n");

		FILE* pFile = fopen("a.txt", "w+");
		fgets(buf, sizeof(buf), pFile);
		tmp = atoi(buf);
		tmp = tmp + 1;
		rewind(pFile);
		fprintf(pFile, "%d", tmp);
		fclose(pFile);
		i++;
		printf("parent do : %d\n", tmp);
		kill(0, SIGUSR2);
	}
	while (i < 3) ;
}

void	Parent_Handler()
{
	turn = ~turn;
}

void	Child_Handler()
{
	turn = ~turn;
}

int main()
{
	pid_t	child_pid;
	int		status;

	parent_pid = getpid();
	child_pid = fork();

	signal(SIGUSR1, Parent_Handler); // SIGUSR1받으면 Parent의 cnt를 ++하
	signal(SIGUSR2, Child_Handler);

    if (child_pid == 0)
	{ 
		/*
		 *Child
		 */
		
        child_do();
        exit(0);
    }
	else
	{
		/*
		 *Parent
		 */
		parent_do();
	}
	waitpid(child_pid, &status, 0);
	printf("final result : %d\n", tmp);
}