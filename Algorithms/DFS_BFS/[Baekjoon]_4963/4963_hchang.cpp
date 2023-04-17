/*
	백준 주소 : https://www.acmicpc.net/problem/4963
	난이도 : 실버2
	문제 이름 : 섬의 갯수
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define MAX 50

int									X, Y;
bool								visited[MAX][MAX];
bool								island[MAX][MAX];
std::queue<std::pair<int, int> >	q;

void	bfs(void)
{
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			std::pair<int, int>	tmp = q.front();
			q.pop();
			if(tmp.first + 1 < X && visited[tmp.second][tmp.first + 1] == false && island[tmp.second][tmp.first + 1] == 1)
			{
				// 우
				q.push(std::make_pair(tmp.first + 1, tmp.second));
				visited[tmp.second][tmp.first + 1] = true;
			}
			if(tmp.second + 1 < Y && visited[tmp.second + 1][tmp.first] == false && island[tmp.second + 1][tmp.first] == 1)
			{
				// 하
				q.push(std::make_pair(tmp.first, tmp.second + 1));
				visited[tmp.second + 1][tmp.first] = true;
			}
			if(tmp.first - 1 >= 0 && visited[tmp.second][tmp.first - 1] == false && island[tmp.second][tmp.first - 1] == 1)
			{
				// 좌
				q.push(std::make_pair(tmp.first - 1, tmp.second));
				visited[tmp.second][tmp.first - 1] = true;
			}
			if(tmp.second - 1 >= 0 && visited[tmp.second - 1][tmp.first] == false && island[tmp.second - 1][tmp.first] == 1)
			{
				// 상
				q.push(std::make_pair(tmp.first, tmp.second - 1));
				visited[tmp.second - 1][tmp.first] = true;
			}
			if(tmp.first - 1 >= 0 && tmp.second - 1 >= 0 && visited[tmp.second - 1][tmp.first - 1] == false && island[tmp.second - 1][tmp.first - 1] == 1)
			{
				// 좌상
				q.push(std::make_pair(tmp.first - 1, tmp.second - 1));
				visited[tmp.second - 1][tmp.first - 1] = true;
			}
			if(tmp.first - 1 >= 0 && tmp.second + 1 < Y && visited[tmp.second + 1][tmp.first - 1] == false && island[tmp.second + 1][tmp.first - 1] == 1)
			{
				// 좌하
				q.push(std::make_pair(tmp.first - 1, tmp.second + 1));
				visited[tmp.second + 1][tmp.first - 1] = true;
			}
			if(tmp.first + 1 < X && tmp.second - 1 >= 0 && visited[tmp.second - 1][tmp.first + 1] == false && island[tmp.second - 1][tmp.first + 1] == 1)
			{
				// 우상
				q.push(std::make_pair(tmp.first + 1, tmp.second - 1));
				visited[tmp.second - 1][tmp.first + 1] = true;
			}
			if(tmp.first + 1 < X && tmp.second + 1 < Y && visited[tmp.second + 1][tmp.first + 1] == false && island[tmp.second + 1][tmp.first + 1] == 1)
			{
				//우하
				q.push(std::make_pair(tmp.first + 1, tmp.second + 1));
				visited[tmp.second + 1][tmp.first + 1] = true;
			}
		}
	}
}


int main()
{
	std::vector<int>	res;
	while (true)
	{
		std::cin >> X >> Y;
		if (X == 0 && Y == 0)
			break ;
		int	tmp(0);
		
		for(int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				std::cin >> island[i][j];
			}
		}

		for(int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (visited[i][j] == false && island[i][j] == 1)
				{
					visited[i][j] = true;
					q.push(std::make_pair(j, i));
					bfs();
					tmp++;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(island, 0, sizeof(island));
		res.push_back(tmp);
	}

	for (int i = 0 ; i < res.size(); i++)
		std::cout << res[i] << std::endl;
}