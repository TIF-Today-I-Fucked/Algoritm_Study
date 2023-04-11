/*
	백준 주소 : https://www.acmicpc.net/problem/11724
	난이도 : 실버2
	문제 이름 : 연결 요소의 개수
*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
vector<int>	arr[1001];
bool		visited[1001];

void	dfs(const int& start)
{
	queue<int>	q;

	q.push(start);
	while (!q.empty())
	{
		const int	front = q.front();
		q.pop();
		if (visited[front])
		{
			continue;
		}
		visited[front] = true;
		for (int i = 0; i < arr[front].size(); i++)
		{
			const int next = arr[front][i];
			if (!visited[next])
			{
				q.push(next);
			}
		}
	}
}

int main()
{
	int node, edge;
	int res(0);
	cin >> node >> edge;
	
	for (int i = 1; i <= edge; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		arr[tmp1].push_back(tmp2);
		arr[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= node; ++i)
	{
		if (!visited[i])
		{
			dfs(i);
			res++;
		}
	}
	std::cout << res;
}