#include <iostream>
#include <queue>

using namespace std;

int	bfs(const int& N, const int& K)
{
	bool		visited[100001] = {0, };
	queue<int>	q;
	int			res(-1);

	q.push(N);
	visited[N] = true;
	const int max = 100001;

	while(!q.empty())
	{
		int	size = q.size();
		++res;

		while (size--)
		{
			const int front = q.front();

			if (front == K)
				return (res);
			
			if (front > 0 && !visited[front - 1])
			{
				q.push(front - 1);
				visited[front - 1] = true;
			}
			if (front + 1 < max && !visited[front + 1])
			{
				q.push(front + 1);
				visited[front + 1] = true;
			}
			if (front * 2 < max && !visited[front * 2])
			{
				q.push(front * 2);
				visited[front * 2] = true;
			}
			q.pop();
		}
	}
	return (res);
}

int	main()
{
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K);
}