#include <cstring>
#include <iostream>
#include <queue>
#include <string.h>

using namespace	std;

bool	map[50][50];
bool	visited[50][50];

void	bfs(const int& x_size, const int& y_size, const int& x, const int& y)
{
	queue<pair<int, int> >	q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty())
	{
		int size = q.size();

		while (size--)
		{
			const int	cur_y = q.front().first;
			const int	cur_x = q.front().second;

			q.pop();
			if (cur_y + 1 < y_size && !visited[cur_y + 1][cur_x] && map[cur_y + 1][cur_x])
			{
				visited[cur_y + 1][cur_x] = true;
				q.push(make_pair(cur_y + 1, cur_x));
			}
			if (cur_x + 1 < x_size && !visited[cur_y][cur_x + 1] && map[cur_y][cur_x + 1])
			{
				visited[cur_y][cur_x + 1] = true;
				q.push(make_pair(cur_y, cur_x + 1));
			}
			if (cur_y > 0 && !visited[cur_y - 1][cur_x] && map[cur_y - 1][cur_x])
			{
				visited[cur_y - 1][cur_x] = true;
				q.push(make_pair(cur_y - 1, cur_x));
			}
			if (cur_x > 0 && !visited[cur_y][cur_x - 1] && map[cur_y][cur_x - 1])
			{
				visited[cur_y][cur_x - 1] = true;
				q.push(make_pair(cur_y, cur_x - 1));
			}
			if (cur_y + 1 < y_size && cur_x + 1 < x_size && !visited[cur_y + 1][cur_x + 1] && map[cur_y + 1][cur_x + 1])
			{
				visited[cur_y + 1][cur_x + 1] = true;
				q.push(make_pair(cur_y + 1, cur_x + 1));
			}
			if (cur_y + 1 < y_size && cur_x > 0 && !visited[cur_y + 1][cur_x - 1] && map[cur_y + 1][cur_x - 1])
			{
				visited[cur_y + 1][cur_x - 1] = true;
				q.push(make_pair(cur_y + 1, cur_x - 1));
			}
			if (cur_y > 0 && cur_x + 1 < x_size && !visited[cur_y - 1][cur_x + 1] && map[cur_y - 1][cur_x + 1])
			{
				visited[cur_y - 1][cur_x + 1] = true;
				q.push(make_pair(cur_y - 1, cur_x + 1));
			}
			if (cur_y > 0 && cur_x > 0 && !visited[cur_y - 1][cur_x - 1] && map[cur_y - 1][cur_x - 1])
			{
				visited[cur_y - 1][cur_x - 1] = true;
				q.push(make_pair(cur_y - 1, cur_x - 1));
			}
			
		}
	}
}

int	main()
{
	while (true)
	{
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		int	x, y;
		cin >> x >> y;
		if (x == 0 && y == 0)
		{
			break ;
		}

		for (int i(0); i < y; ++i)
		{
			for (int k(0); k < x; ++k)
			{
				cin >> map[i][k];
			}
		}

		int	res(0);

		for (int i(0); i < y; ++i)
		{
			for (int k(0); k < x; ++k)
			{
				if (!visited[i][k] && map[i][k])
				{
					bfs(x, y, k, i);
					++res;
				}
			}
		}
		cout << res << "\n";
	}
}