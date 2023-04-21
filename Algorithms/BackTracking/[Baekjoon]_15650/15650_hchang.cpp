/*
	백준 주소 : https://www.acmicpc.net/problem/15650
	난이도 : 실버3
	문제 이름 : N과 M(2)
*/

#include <iostream>

const int	MAX = 8;
int			N, M;
int			arr[MAX];
bool		visited[MAX];

// N까지
// M개

void	dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
		return ;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			if (cnt != 0 && arr[cnt - 1] > i + 1)
			{
				visited[i] = false;
				continue;
			}
			arr[cnt] = i + 1;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int	main()
{
	std::cin >> N >> M;
	dfs(0);
}