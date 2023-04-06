/*
	백준 주소 : https://www.acmicpc.net/problem/1325
	난이도 : 실버1
	문제 이름 : 효율적인 해킹
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

bool		visited[10001];
vector<int>	arr[10001];

int	dfs(const int& start)
{
	bzero(&visited, sizeof(visited));
	queue<int>	q;
	int			res(0);

	q.push(start);
	while (!q.empty())
	{
		const int cur = q.front();
		if (visited[cur])
			continue ;
		q.pop();
		visited[cur] = true;
		for (int i(0); i < arr[cur].size(); ++i)
		{
			const int next = arr[cur][i];
			if (!visited[next])
			{
				q.push(next);
				res++;
			}
		}
	}
	return (res);
}

int	main()
{
	int	node, n;
	cin >> node >> n;

	vector<int>	ans(node + 1);
	for (int i(1); i <= n; ++i)
	{
		int	a, b;
		cin >> a >> b;
		arr[b].push_back(a);
	}
	for (int i(1); i <= node; ++i)
	{
		const int	res = dfs(i);
		ans[i] = res;
	}
	const int max = *max_element(ans.begin(), ans.end());
	for (int i(0); i < ans.size(); ++i)
	{
		if (ans[i] == max)
			cout << i << " ";
	}
}