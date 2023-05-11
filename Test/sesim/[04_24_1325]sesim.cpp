#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int	N, M;
vector<int>	arr[10001];

int	bfs(const int& start)
{
	bool		visited[10001] = {0, };
	int			res(0);
	queue<int>	q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		const int front = q.front();
		q.pop();
		for (int i(0); i < arr[front].size(); ++i)
		{
			const int cur = arr[front].at(i);
			if (!visited[cur])
			{
				res++;
				q.push(cur);
				visited[cur] = true;
			}
		}
	}
	return (res);
}

int	main()
{
	cin >> N >> M;
	for (int i(0); i < M; ++i)
	{
		int	tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		arr[tmp2].push_back(tmp1);
	}

	vector<int>	res(N + 1);
	for (int i(1); i <= N; ++i)
	{
		res[i] = bfs(i);
	}
	const int max = *max_element(res.begin(), res.end());
	const int size = res.size();
	for (int i(1); i < size; ++i)
	{
		if (res[i] == max)
			cout << i << " ";
	}
}