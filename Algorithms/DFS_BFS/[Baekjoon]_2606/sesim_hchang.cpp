/*
	백준 주소 : https://www.acmicpc.net/problem/2606
	난이도 : 실버3
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

vector<int> adjList[101];
bool		visited[101];


int	dfs(int start)
{
	bzero(&visited, sizeof(visited));
	int			res(-1);
	stack<int>	s;
	
	s.push(start);
	while (!s.empty())
	{
		const int	cur = s.top();
		s.pop();
		if (visited[cur])
		{
			continue ;
		}
		visited[cur] = true;
		res++;
		for (int i(0); i < adjList[cur].size(); ++i)
		{
			const int	next = adjList[cur][i];
			if (!visited[next])
			{
				s.push(next);
			}
		}
	}
	return (res);
}

int main()
{
	int node, edge;

	cin >> node >> edge;

	for (int i = 0; i < edge; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adjList[tmp1].push_back(tmp2);
		adjList[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= node; i++)
	{
		sort(adjList[i].begin(), adjList[i].end(), less<int>());
	}
	
	int res(0);
	for (int i = 1 ; i <= node; i++)
	{
		const int	tmp = dfs(i);
		res = res > tmp ? res : tmp;
	}
	cout << res;

}