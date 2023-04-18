/*
	백준 주소 : https://www.acmicpc.net/problem/10026
	난이도 : 골드5
	문제 이름 : 적록색양
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define MAX 100

int		num;
char	rgb[MAX][MAX];
char	rrb[MAX][MAX];
bool	visited[MAX][MAX];
std::queue<std::pair<int, int> >	q;
		
void	bfs1(char target)
{
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			std::pair<int, int>	tmp = q.front();
			q.pop();
			if (tmp.first + 1 < num && visited[tmp.second][tmp.first + 1] == false && target == rgb[tmp.second][tmp.first + 1])
			{
				q.push(std::make_pair(tmp.first + 1, tmp.second));
				visited[tmp.second][tmp.first + 1] = true;
			}
			if (tmp.second + 1 < num && visited[tmp.second + 1][tmp.first] == false && target == rgb[tmp.second + 1][tmp.first])
			{
				q.push(std::make_pair(tmp.first, tmp.second + 1));
				visited[tmp.second + 1][tmp.first] = true;
			}
			if (tmp.first - 1 >= 0 && visited[tmp.second][tmp.first - 1] == false && target == rgb[tmp.second][tmp.first - 1])
			{
				q.push(std::make_pair(tmp.first - 1, tmp.second));
				visited[tmp.second][tmp.first - 1] = true;
			}
			if (tmp.second - 1 >= 0 && visited[tmp.second - 1][tmp.first] == false && target == rgb[tmp.second - 1][tmp.first])
			{
				q.push(std::make_pair(tmp.first, tmp.second - 1));
				visited[tmp.second - 1][tmp.first] = true;
			}
		}
	}
}


void	bfs2(char target)
{
	//std::cout << "============= <bfs>  ===============\n";
	while (!q.empty())
	{
		int size = q.size();
		//std::cout << "size : " << size << std::endl;
		while (size--)
		{
			std::pair<int, int>	tmp = q.front();
			q.pop();
			if (tmp.first + 1 < num && visited[tmp.second][tmp.first + 1] == false && target == rrb[tmp.second][tmp.first + 1])
			{
				q.push(std::make_pair(tmp.first + 1, tmp.second));
				visited[tmp.second][tmp.first + 1] = true;
			}
			if (tmp.second + 1 < num && visited[tmp.second + 1][tmp.first] == false && target == rrb[tmp.second + 1][tmp.first])
			{
				q.push(std::make_pair(tmp.first, tmp.second + 1));
				visited[tmp.second + 1][tmp.first] = true;
			}
			if (tmp.first - 1 >= 0 && visited[tmp.second][tmp.first - 1] == false && target == rrb[tmp.second][tmp.first - 1])
			{
				q.push(std::make_pair(tmp.first - 1, tmp.second));
				visited[tmp.second][tmp.first - 1] = true;
			}
			if (tmp.second - 1 >= 0 && visited[tmp.second - 1][tmp.first] == false && target == rrb[tmp.second - 1][tmp.first])
			{
				q.push(std::make_pair(tmp.first, tmp.second - 1));
				visited[tmp.second - 1][tmp.first] = true;
			}
		}
	}
}

int main()
{
	int			final_res[2] = {0, };
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			std::cin >> rgb[i][j];
			if (rgb[i][j] == 'G')
			{
				rrb[i][j] = 'R';
				continue;
			}
			rrb[i][j] = rgb[i][j];
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (visited[i][j] == false)
			{
				visited[i][j] = true;
				q.push(std::make_pair(j, i));
				bfs1(rgb[i][j]);
				final_res[0]++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (visited[i][j] == false)
			{
				visited[i][j] = true;
				q.push(std::make_pair(j, i));
				bfs2(rrb[i][j]);
				final_res[1]++;

			}
		}
	}

	std::cout << final_res[0] << " " << final_res[1];	
}