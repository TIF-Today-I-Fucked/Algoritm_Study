/*
	백준 주소 : https://www.acmicpc.net/problem/2468
	난이도 : 실버1
	문제 이름 : 안전영역
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

const int							MAX = 100;
int									num;
int									map[MAX][MAX];
bool								visited[MAX][MAX];
std::queue<std::pair<int, int> >	q;

void	bfs(int water)
{
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int	cur_x = q.front().first;
			int	cur_y = q.front().second;
			q.pop();
			if (map[cur_y][cur_x + 1] >= water && cur_x + 1 < num && visited[cur_y][cur_x + 1] == false)
			{
				q.push(std::make_pair(cur_x + 1, cur_y));
				visited[cur_y][cur_x + 1] = true;
			}
			if (map[cur_y + 1][cur_x] >= water && cur_y + 1 < num && visited[cur_y + 1][cur_x] == false)
			{
				q.push(std::make_pair(cur_x, cur_y + 1));
				visited[cur_y + 1][cur_x] = true;
			}
			if (map[cur_y][cur_x - 1] >= water && cur_x - 1 >= 0 && visited[cur_y][cur_x - 1] == false)
			{
				q.push(std::make_pair(cur_x - 1, cur_y));
				visited[cur_y][cur_x - 1] = true;
			}
			if (map[cur_y - 1][cur_x] >= water && cur_y - 1 >= 0 && visited[cur_y - 1][cur_x] == false)
			{
				q.push(std::make_pair(cur_x, cur_y - 1));
				visited[cur_y - 1][cur_x] = true;
			}
		}
	}
}

int main()
{
	std::vector<int>	res;
	std::cin >> num;
	int	max_n = 0;
	int	min_n = 101;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] > max_n)
				max_n = map[i][j];
			if (map[i][j] < min_n)
				min_n = map[i][j];
		}
	}

	int tmp(0);
	for(int water = min_n; water < max_n; water++)	
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (visited[i][j] == false && map[i][j] >= water)
				{
					q.push(std::make_pair(j, i));
					visited[i][j] = true;
					bfs(water);
					tmp++;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		res.push_back(tmp);
		tmp = 0;
	}
	std::sort(res.begin(), res.end());

	std::cout << res[res.size() - 1] << std::endl;
}