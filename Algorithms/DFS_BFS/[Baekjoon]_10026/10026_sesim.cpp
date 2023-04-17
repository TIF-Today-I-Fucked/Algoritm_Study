#include <iostream>
#include <string.h>
#include <new>
#include <queue>
#include <vector>

using namespace std;

int		N;
bool	visited[100][100];

void	bfs(char** map, const int& x, const int& y, const char& cur)
{
	queue<pair<int, int> >	q;

	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int size = q.size();

		while (size--)
		{
			const int cur_y = q.front().first;
			const int cur_x = q.front().second;

			visited[cur_y][cur_x] = true;
			if (cur_y + 1 < N && !visited[cur_y + 1][cur_x] && map[cur_y + 1][cur_x] == cur)
			{
				visited[cur_y + 1][cur_x] = true;
				q.push(make_pair(cur_y + 1, cur_x));
			}
			if (cur_x + 1 < N && !visited[cur_y][cur_x + 1] && map[cur_y][cur_x + 1] == cur)
			{
				visited[cur_y][cur_x + 1] = true;
				q.push(make_pair(cur_y, cur_x + 1));
			}
			if (cur_y > 0 && !visited[cur_y - 1][cur_x] && map[cur_y - 1][cur_x] == cur)
			{
				visited[cur_y - 1][cur_x] = true;
				q.push(make_pair(cur_y - 1, cur_x));
			}
			if (cur_x > 0 && !visited[cur_y][cur_x - 1] && map[cur_y][cur_x - 1] == cur)
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
	cin >> N;
	char	**normal_map;
	char	**odd_map;

	normal_map = new char*[N];
	odd_map = new char*[N];
	for (int i(0); i < N; ++i)
	{
		normal_map[i] = new char[N];
		odd_map[i] = new char[N];
		for (int k(0); k < N; ++k)
		{
			cin >> normal_map[i][k];
			odd_map[i][k] = (normal_map[i][k] == 'G' ? 'R' : normal_map[i][k]);
		}
	}

	int	normal_res(0);
	int	odd_res(0);

	for (int i(0); i < N; ++i)
	{
		for (int k(0); k < N; ++k)
		{
			if (!visited[i][k])
			{
				bfs(normal_map, k, i, normal_map[i][k]);
				++normal_res;
			}
		}
	}

	memset(&visited, 0, sizeof(visited));
	for (int i(0); i < N; ++i)
	{
		for (int k(0); k < N; ++k)
		{
			if (visited[i][k])
			{
				continue;
			}
			bfs(odd_map, k, i, odd_map[i][k]);
			++odd_res;
		}
	}

	cout << normal_res << " " << odd_res;
	for (int i(0); i < N; ++i)
	{
		delete [] normal_map[i];
		delete [] odd_map[i];
	}
	delete [] normal_map;
	delete [] odd_map;
}