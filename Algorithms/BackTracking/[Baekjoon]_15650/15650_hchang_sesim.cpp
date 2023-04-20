/*
	백준 주소 : https://www.acmicpc.net/problem/15650
	난이도 : 실버3
	문제 이름 : N과 M(2)
*/

#include <iostream>

using namespace std;

const int	MAX = 9;
bool		visited[MAX];
int			arr[MAX];
int			N,M;

void	dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i(0); i < M; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i(0); i < N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			if (cnt > 0 && arr[cnt - 1] > i + 1)
			{
				visited[i] = false;
				continue ;
			}
			arr[cnt] = i + 1;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int	main()
{
	cin >> N >> M;
	dfs(0);
}