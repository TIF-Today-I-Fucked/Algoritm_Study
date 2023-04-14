#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace	std;
bool	visited[50][50];
int		x_len, y_len;

void	bfs(vector<vector<int> >& map, const int& x, const int& y)
{
	queue<pair<int, int> >	q;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		int	size = q.size();

		while (size--)
		{
			const int	cur_x = q.front().second;
			const int	cur_y = q.front().first;

			visited[cur_y][cur_x] = true;
			if (cur_y + 1 < y_len && !visited[cur_y + 1][cur_x] && map[cur_y + 1][cur_x] == 1)
			{
				visited[cur_y + 1][cur_x] = true;
				q.push(make_pair(cur_y + 1, cur_x));
			}
			if (cur_x + 1 < x_len && !visited[cur_y][cur_x + 1] && map[cur_y][cur_x + 1] == 1)
			{
				visited[cur_y][cur_x + 1] = true;
				q.push(make_pair(cur_y, cur_x + 1));
			}
			if (cur_y - 1 >= 0 && !visited[cur_y - 1][cur_x] && map[cur_y - 1][cur_x] == 1)
			{
				visited[cur_y - 1][cur_x] = true;
				q.push(make_pair(cur_y - 1, cur_x));
			}
			if (cur_x - 1 >= 0 && !visited[cur_y][cur_x - 1] && map[cur_y][cur_x - 1] == 1)
			{
				visited[cur_y][cur_x - 1] = true;
				q.push(make_pair(cur_y, cur_x - 1));
			}
			q.pop();
		}
	}

}

int	main()
{
	int	n;
	cin >> n;

	int	res[n];
	fill(res, res + n, 0);
	for (int i(0); i < n; ++i)
	{
		int	total;
		cin >> x_len >> y_len >> total;
		fill(&visited[0][0], &visited[50 - 1][50], 0);
		vector<vector<int> >	map;
		map.resize(y_len, vector<int>(x_len, 0));
		for (int k(0); k < total; ++k)
		{
			int	cur_x, cur_y;
			cin >> cur_x >> cur_y;
			map[cur_y][cur_x] = 1;
		}
		for (int cur_y = 0; cur_y < y_len; ++cur_y)
		{
			for (int cur_x = 0; cur_x < x_len; ++cur_x)
			{
				if (map[cur_y][cur_x] == 0 || visited[cur_y][cur_x])
					continue ;
				bfs(map, cur_x, cur_y);
				res[i]++;
			}
		}
	}
	for (int i(0); i < n; ++i)
	{
		cout << res[i] << endl;
	}
}