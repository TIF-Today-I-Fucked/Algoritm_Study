/*
	백준 주소 : https://www.acmicpc.net/problem/7569
	난이도 : 골드5
	문제 이름 : 토마토 Ver.2
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100

int								X,Y,Z;
int								map[MAX][MAX][MAX];
std::queue<std::vector<int> >	q;
bool							visited[MAX][MAX][MAX];

int	bfs(void)
{
	int res(-1);
	while (!q.empty())
	{
		int size = q.size();
		res++;
		while(size--)
		{
			int	cur_x = q.front()[0];
			int	cur_y = q.front()[1];
			int	cur_z = q.front()[2];
			q.pop();
			if (cur_x + 1 < X && visited[cur_z][cur_y][cur_x + 1] == false && map[cur_z][cur_y][cur_x + 1] == 0)
			{
				std::vector<int> tmp = {cur_x + 1, cur_y, cur_z};
				visited[cur_z][cur_y][cur_x + 1] = true;
				map[cur_z][cur_y][cur_x + 1] = 1;
				q.push(tmp);
			}
			if (cur_y + 1 < Y && visited[cur_z][cur_y + 1][cur_x] == false && map[cur_z][cur_y + 1][cur_x] == 0)
			{
				std::vector<int> tmp = {cur_x, cur_y + 1, cur_z};
				visited[cur_z][cur_y + 1][cur_x] = true;
				map[cur_z][cur_y + 1][cur_x] = 1;
				q.push(tmp);
			}
			if (cur_z + 1 < Z && visited[cur_z + 1][cur_y][cur_x] == false && map[cur_z + 1][cur_y][cur_x] == 0)
			{
				std::vector<int> tmp = {cur_x, cur_y, cur_z + 1};
				visited[cur_z + 1][cur_y][cur_x] = true;
				map[cur_z + 1][cur_y][cur_x] = 1;
				q.push(tmp);
			}
			if (cur_x - 1 >= 0 && visited[cur_z][cur_y][cur_x - 1] == false && map[cur_z][cur_y][cur_x - 1] == 0)
			{
				std::vector<int> tmp = {cur_x - 1, cur_y, cur_z};
				visited[cur_z][cur_y][cur_x - 1] = true;
				map[cur_z][cur_y][cur_x - 1] = 1;
				q.push(tmp);
			}
			if (cur_y - 1 >= 0 && visited[cur_z][cur_y - 1][cur_x] == false && map[cur_z][cur_y - 1][cur_x] == 0)
			{
				
				std::vector<int> tmp = {cur_x, cur_y - 1, cur_z};
				visited[cur_z][cur_y - 1][cur_x] = true;
				map[cur_z][cur_y - 1][cur_x] = 1;
				q.push(tmp);
			}
			if (cur_z - 1 >= 0 && visited[cur_z - 1][cur_y][cur_x] == false && map[cur_z - 1][cur_y][cur_x] == 0)
			{
				std::vector<int> tmp = {cur_x, cur_y, cur_z - 1};
				visited[cur_z - 1][cur_y][cur_x] = true;
				map[cur_z - 1][cur_y][cur_x] = 1;
				q.push(tmp);
			}
		}
	}
	return res;
}

int main()
{
	int	res(0);
	std::cin >> X >> Y >> Z;

	for(int i = 0; i < Z; i++)
	{
		for(int j = 0; j < Y; j++)
		{
			for(int k = 0; k < X; k++)
			{
				std::cin >> map[i][j][k];
				if (map[i][j][k] == 1)
				{
					std::vector<int>	tmp = {k, j, i};
					visited[i][j][k] = true;
					q.push(tmp);
				}
			}
		}
	}	
	res = bfs();
	for(int i = 0; i < Z; i++)
	{
		for(int j = 0; j < Y; j++)
		{
			for(int k = 0; k < X; k++)
			{
				if (map[i][j][k] == 0)
				{
					std::cout << "-1\n";
					return 0;
				}
			}
		}
	}
	std::cout << res << "\n";
}
