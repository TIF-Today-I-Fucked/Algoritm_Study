/*
	백준 주소 : https://www.acmicpc.net/problem/7562
	난이도 : 실버1
	문제 이름 : 나이트의 이동
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

const int							MAX = 300;
int									NUM;
bool								visited[MAX][MAX];

int	bfs(int& map_size, std::pair<int, int>& start_point, std::pair<int, int>& end_point)
{
	int res(0);
	std::queue<std::pair<int, int> >	q;
	q.push(start_point);
	visited[start_point.second][start_point.first] = true;
	while (!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int	cur_x = q.front().first;
			int	cur_y = q.front().second;
			q.pop();
			if (cur_x == end_point.first && cur_y == end_point.second)
				return res;
			if(cur_x + 2 < map_size && cur_y + 1 < map_size && visited[cur_y + 1][cur_x + 2] == false)
			{
				q.push(std::make_pair(cur_x + 2, cur_y + 1));
				visited[cur_y + 1][cur_x + 2] = true;
			}
			if(cur_x + 1 < map_size && cur_y + 2 < map_size && visited[cur_y + 2][cur_x + 1] == false)
			{
				q.push(std::make_pair(cur_x + 1, cur_y + 2));
				visited[cur_y + 2][cur_x + 1] = true;
			}

			if(cur_x + 2 < map_size && cur_y - 1 >= 0 && visited[cur_y - 1][cur_x + 2] == false)
			{
				q.push(std::make_pair(cur_x + 2, cur_y - 1));
				visited[cur_y - 1][cur_x + 2] = true;
			}
			if(cur_x + 1 < map_size && cur_y - 2 >= 0 && visited[cur_y - 2][cur_x + 1] == false)
			{
				q.push(std::make_pair(cur_x + 1, cur_y - 2));
				visited[cur_y - 2][cur_x + 1] = true;
			}
			if(cur_x - 2 >= 0 && cur_y + 1 < map_size && visited[cur_y + 1][cur_x - 2] == false)
			{
				q.push(std::make_pair(cur_x - 2, cur_y + 1));
				visited[cur_y + 1][cur_x - 2] = true;
			}
			if(cur_x - 1 >= 0 && cur_y + 2 < map_size && visited[cur_y + 2][cur_x - 1] == false)
			{
				q.push(std::make_pair(cur_x - 1, cur_y + 2));
				visited[cur_y + 2][cur_x - 1] = true;
			}

			if(cur_x - 2 >= 0 && cur_y - 1 >= 0 && visited[cur_y - 1][cur_x - 2] == false)
			{
				q.push(std::make_pair(cur_x - 2, cur_y - 1));
				visited[cur_y - 1][cur_x - 2] = true;
			}
			if(cur_x - 1 >= 0 && cur_y - 2 >= 0 && visited[cur_y - 2][cur_x - 1] == false)
			{
				q.push(std::make_pair(cur_x - 1, cur_y - 2));
				visited[cur_y - 2][cur_x - 1] = true;
			}
		}
		res++;
	}
	return res;
}


int main()
{
	int	map_size(0);
	std::vector<int>	res;
	std::pair<int, int>	start_point;
	std::pair<int, int>	end_point;

	std::cin >> NUM;

	for (int i = 0; i < NUM; i++)
	{
		std::cin >> map_size;
		std::cin >> start_point.first >> start_point.second;
		std::cin >> end_point.first >> end_point.second;
		res.push_back(bfs(map_size, start_point, end_point));
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 0; i < NUM; i++)
	{
		std::cout << res[i] << std::endl;
	}
	
}