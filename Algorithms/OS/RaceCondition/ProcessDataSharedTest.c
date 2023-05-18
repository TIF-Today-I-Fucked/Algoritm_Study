#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int state;
int cnt = 0;

void	child_do()
{
	printf("child cnt : %p, %d\n", &cnt, cnt);
	for (int i = 0; i < 3; i++)
	{
		printf("child do\n");
		cnt += 2;
	}
}

void	parent_do()
{
	printf("parent cnt : %p, %d\n", &cnt, cnt);
	for (int i = 0; i < 3; i++)
	{
		printf("parent do\n");
		cnt += 1;
	}
}

int main()
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		child_do();
		//exit(0);
	}
	else
	{
		parent_do();
	}
	waitpid(pid, &state, 0);
	printf("final result : %d\n", cnt);
}