#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	buf[1024];
int		tmp = 0;
int		turn1 = 0;
int		turn2 = 1;

void	child_do()
{
	printf("child_do Start\n");
	int i = 0;
	do
	{
		printf("after turn : %d\n", turn1);
		while (turn1 != 0) ;
		// critical section
		FILE* pFile = fopen("a.txt", "w+");
		fgets(buf, sizeof(buf), pFile);
		printf("Child buf : %s\n", buf);
		tmp = atoi(buf);
		printf("Child bef : %d\n", tmp);
		tmp = tmp + 1;
		printf("Child aft : %d\n", tmp);
		rewind(pFile);
		fprintf(pFile, "%d", tmp);
		fclose(pFile);
		turn1 = 1;
		turn2 = turn1;
		printf("bro : %d\n", turn1);
		i++;
	}
	while (i < 3) ;
}

void	parent_do()
{
	printf("parent_do Start\n");
	int	i = 0;
	do
	{
		while (turn2 != 1) 
		{
			// printf("what : %d\n", turn);
		}
		// critical section
		FILE* pFile = fopen("a.txt", "w+");
		fgets(buf, sizeof(buf), pFile);
		printf("Parent buf : %s\n", buf);
		tmp = atoi(buf);
		printf("Parent bef : %d\n", tmp);
		tmp = tmp + 1;
		printf("Parent aft : %d\n", tmp);
		rewind(pFile);
		fprintf(pFile, "%d", tmp);
		fclose(pFile);
		turn2 = 0;
		turn1 = turn2;
		i++;
	}
	while (i < 3) ;
}

int main()
{
	pid_t	pid;
	int		status;

	pid = fork();
    if (pid == 0)
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
	waitpid(pid, &status, 0);
	printf("final! : %d\n", tmp);
}