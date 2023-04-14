#include <iostream>
#include <queue>
#include <vector>

using namespace	std;
bool	visitied[1000][1000];

int	bfs(int** map, queue<pair<int, int> >& q, const int& x_size, const int& y_size)
{
	int	res(-1);

	while (!q.empty())
	{
		int	size = q.size();

		while (size--)
		{
			const int	x = q.front().second;
			const int	y = q.front().first;

			visitied[y][x] = true;
			if (y + 1 < y_size && !visitied[y + 1][x] && map[y + 1][x] == 0)
			{
				visitied[y + 1][x] = true;
				map[y + 1][x] = 1;
				q.push(make_pair(y + 1, x));
			}
			if (x + 1 < x_size && !visitied[y][x + 1] && map[y][x + 1] == 0)
			{
				visitied[y][x + 1] = true;
				map[y][x + 1] = 1;
				q.push(make_pair(y, x + 1));
			}
			if (y > 0 && !visitied[y - 1][x] && map[y - 1][x] == 0)
			{
				visitied[y - 1][x] = true;
				map[y - 1][x] = 1;
				q.push(make_pair(y - 1, x));
			}
			if (x > 0 && !visitied[y][x - 1] && map[y][x - 1] == 0)
			{
				visitied[y][x - 1] = true;
				map[y][x - 1] = 1;
				q.push(make_pair(y, x - 1));
			}
			q.pop();
		}
		res++;	
	}
	return (res);
}


int	main()
{
	int	x, y;
	cin >> x >> y;
	queue<pair<int, int> >	q;

	int** map = new int*[y];
	for (int i(0); i < y; ++i)
	{
		map[i] = new int[x];
		for (int k(0); k < x; ++k)
		{
			cin >> map[i][k];
			if (map[i][k] == 1)
			{
				q.push(make_pair(i, k));
			}
		}
	}
	int	res = bfs(map, q, x, y);
	for (int i(0); i < y; ++i)
	{
		for (int k(0); k < x; ++k)
		{
			if (map[i][k] == 0)
			{
				res = -1;
			}
		}
		delete [] map[i];
	}
	delete [] map;
	cout << res;
}