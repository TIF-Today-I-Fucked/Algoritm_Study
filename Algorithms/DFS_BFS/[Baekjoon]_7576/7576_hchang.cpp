/*
	백준 주소 : https://www.acmicpc.net/problem/7576
	난이도 : 골드5
	문제 이름 : 토마토
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define MAX 1000

std::queue<std::pair<int, int> >	q;
int									map[MAX][MAX];
bool								visited[MAX][MAX];
int									M, N;

int	bfs(int x, int y)
{
	int res(-1);

	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			std::pair<int, int>	tmp = q.front();
			q.pop();
			if (tmp.first + 1 < M && map[tmp.second][tmp.first + 1] == 0 && visited[tmp.second][tmp.first + 1] != 1)
			{
				q.push(std::make_pair(tmp.first + 1, tmp.second));
				map[tmp.second][tmp.first + 1] = 1;
				visited[tmp.second][tmp.first + 1] = true;
			}
			if (tmp.second + 1 < N && map[tmp.second + 1][tmp.first] == 0 && visited[tmp.second + 1][tmp.first] != 1)
			{
				q.push(std::make_pair(tmp.first, tmp.second + 1));
				map[tmp.second + 1][tmp.first] = 1;
				visited[tmp.second + 1][tmp.first] = true;
			}
			if (tmp.first - 1 >= 0 && map[tmp.second][tmp.first - 1] == 0 && visited[tmp.second][tmp.first - 1] != 1)
			{
				q.push(std::make_pair(tmp.first - 1, tmp.second));
				map[tmp.second][tmp.first - 1] = 1;
				visited[tmp.second][tmp.first - 1] = true;

			}
			if (tmp.second - 1 >= 0 && map[tmp.second - 1][tmp.first] == 0 && visited[tmp.second - 1][tmp.first] != 1)
			{
				q.push(std::make_pair(tmp.first, tmp.second - 1));
				map[tmp.second - 1][tmp.first] = 1;
				visited[tmp.second - 1][tmp.first] = true;
			}
		}
		res++;
	}
	return res;
}


int main()
{
	int res;
	std::cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push(std::make_pair(j, i));
				visited[i][j] = true;
			}
		}
	}
	res = bfs(q.front().first, q.front().second);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(map[i][j] == 0)
			{
				std::cout << -1 << std::endl;
				return 0;
			}
		}
	}
	std::cout << res << std::endl;
}
