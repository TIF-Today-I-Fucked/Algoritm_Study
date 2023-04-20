#include <iostream>
#include <iterator>
#include <queue>

using namespace	std;

int		map[100][100][100];
bool	visited[100][100][100];

int		x, y, z;

int	bfs(queue<pair<int, pair<int, int> > >& q)
{
	int	res(-1);

	while (!q.empty())
	{
		int	size = q.size();
		++res;
		
		while (size--)
		{
			const int	cur_x = q.front().first;
			const int	cur_y = q.front().second.first;
			const int	cur_z = q.front().second.second;

			q.pop();
			if (cur_z + 1 < z && !visited[cur_z + 1][cur_y][cur_x] && map[cur_z + 1][cur_y][cur_x] == 0)
			{
				visited[cur_z + 1][cur_y][cur_x] = true;
				map[cur_z + 1][cur_y][cur_x] = 1;
				q.push(make_pair(cur_x, make_pair(cur_y, cur_z + 1)));
			}
			if (cur_z > 0 && !visited[cur_z - 1][cur_y][cur_x] && map[cur_z - 1][cur_y][cur_x] == 0)
			{
				visited[cur_z - 1][cur_y][cur_x] = true;
				map[cur_z - 1][cur_y][cur_x] = 1;
				q.push(make_pair(cur_x, make_pair(cur_y, cur_z - 1)));
			}
			if (cur_y + 1 < y && !visited[cur_z][cur_y + 1][cur_x] && map[cur_z][cur_y + 1][cur_x] == 0)
			{
				visited[cur_z][cur_y + 1][cur_x] = true;
				map[cur_z][cur_y + 1][cur_x] = 1;
				q.push(make_pair(cur_x, make_pair(cur_y + 1, cur_z)));
			}
			if (cur_y > 0 && !visited[cur_z][cur_y - 1][cur_x] && map[cur_z][cur_y - 1][cur_x] == 0)
			{
				visited[cur_z][cur_y - 1][cur_x] = true;
				map[cur_z][cur_y - 1][cur_x] = 1;
				q.push(make_pair(cur_x, make_pair(cur_y - 1, cur_z)));
			}
			if (cur_x + 1 < x && !visited[cur_z][cur_y][cur_x + 1] && map[cur_z][cur_y][cur_x + 1] == 0)
			{
				visited[cur_z][cur_y][cur_x + 1] = true;
				map[cur_z][cur_y][cur_x + 1] = 1;
				q.push(make_pair(cur_x + 1, make_pair(cur_y, cur_z)));
			}
			if (cur_x > 0 && !visited[cur_z][cur_y][cur_x - 1] && map[cur_z][cur_y][cur_x - 1] == 0)
			{
				visited[cur_z][cur_y][cur_x - 1] = true;
				map[cur_z][cur_y][cur_x - 1] = 1;
				q.push(make_pair(cur_x - 1, make_pair(cur_y, cur_z)));
			}
		}

	}
	return (res);
}

int	main()
{
	queue<pair<int, pair<int, int> > >	q;
	cin >> x >> y >> z;
	for (int i(0); i < z; ++i)
	{
		for (int k(0); k < y; ++k)
		{
			for (int n(0); n < x; ++n)
			{
				cin >> map[i][k][n];
				if (map[i][k][n] == 1)
				{
					q.push(make_pair(n, make_pair(k, i)));
					visited[i][k][n] = true;
				}
			}
		}
	}
	int	res = bfs(q);
	for (int i(0); i < z; ++i)
	{
		for (int k(0); k < y; ++k)
		{
			for (int n(0); n < x; ++n)
			{
				if (map[i][k][n] == 0)
				{
					res = -1;
					break ;
				}
			}
		}
	}
	cout << res;
}