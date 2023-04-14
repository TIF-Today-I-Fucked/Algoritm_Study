/*
	백준 주소 : https://www.acmicpc.net/problem/1012
	난이도 : 실버2
	문제 이름 : 유기능 배추
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define MAX 50
int		map[MAX][MAX];
bool	visited[MAX][MAX];

void	dfs(int x, int y, int size_x, int size_y)
{
	visited[y][x] = true;

	if (y + 1 < size_y && map[y + 1][x] == 1 && visited[y + 1][x] != 1)
		dfs(x, y + 1, size_x, size_y);
	if (x + 1 < size_x && map[y][x + 1] == 1 && visited[y][x + 1] != 1)
		dfs(x + 1, y, size_x, size_y);
	if (0 < y && map[y - 1][x] == 1 && visited[y - 1][x] != 1)
		dfs(x, y - 1, size_x, size_y);
	if (0 < x && map[y][x - 1] == 1 && visited[y][x - 1] != 1)
		dfs(x - 1, y, size_x, size_y);
}

int main()
{
	int num;
	std::vector<int>	res;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		int size_x, size_y, one_cnt;
		std::cin >> size_x >> size_y >> one_cnt;

		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < one_cnt; j++)
		{
			int x, y;
			std::cin >> x >> y;
			map[y][x] = 1;
		}

		int tmp(0);
		for (int a = 0; a < size_y; a++)
		{
			for (int b = 0; b < size_x; b++)
			{
				if(map[a][b] == 1 && visited[a][b] != 1)
				{
					dfs(b, a, size_x, size_y);
					tmp++;
				}
			}
		}
		res.push_back(tmp);
	}
	for (int i = 0 ; i < num; i++)
		std::cout << res[i] << std::endl;
}