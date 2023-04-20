/*
	백준 주소 : https://www.acmicpc.net/problem/15649
	난이도 : 실버3
	문제 이름 : N과 M(1)
*/

#include <iostream>

using namespace	std;

const int	MAX = 9;
int N,M;
int	arr[MAX];
int visited[MAX];

// [입력]
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

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
