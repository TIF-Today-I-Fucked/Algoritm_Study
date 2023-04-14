#include <iostream>
#include <queue>

using namespace	std;
int	map[8][8];
int	copy_map[8][8];
int	N, M;
queue<pair<int, int> >	virus_pos;


void	bfs()
{
	queue<pair<int, int> >	q(virus_pos);
	bool	visited[8][8] = {0, };


	while (!q.empty())
	{
		int size = q.size();
		
		while (size--)
		{
			const int x = q.front().second;
			const int y = q.front().first;

			visited[y][x] = true;

			if (y + 1 < N && !visited[y + 1][x] && copy_map[y + 1][x] == 0)
			{
				visited[y + 1][x] = true;
				copy_map[y + 1][x] = 2;
				q.push(make_pair(y + 1, x));
			}
			if (x + 1 < M && !visited[y][x + 1] && copy_map[y][x + 1] == 0)
			{
				visited[y][x + 1] = true;
				copy_map[y][x + 1] = 2;
				q.push(make_pair(y, x + 1));
			}
			if (y > 0 && !visited[y - 1][x] && copy_map[y - 1][x] == 0)
			{
				visited[y - 1][x] = true;
				copy_map[y - 1][x] = 2;
				q.push(make_pair(y - 1, x));
			}
			if (x > 0 && !visited[y][x - 1] && copy_map[y][x - 1] == 0)
			{
				visited[y][x - 1] = true;
				copy_map[y][x - 1] = 2;
				q.push(make_pair(y, x - 1));
			}
			q.pop();
		}
	}
}

int	buildColumn(const int first_x, const int first_y,
		const int second_x, const int second_y,
		const int third_x, const int third_y)
{
	int	res(0);

	for (int i(0); i < N; ++i)
	{
		for (int k(0); k < M; ++k)
		{
			copy_map[i][k] = map[i][k];
		}
	}
	copy_map[first_y][first_x] = 1;
	copy_map[second_y][second_x] = 1;
	copy_map[third_y][third_x] = 1;
	bfs();
	
	for (int i(0); i < N; ++i)
	{
		for (int k(0); k < M; ++k)
		{
			if (copy_map[i][k] == 0)
			{
				++res;
			}
		}
	}
	return (res);
}

int	findBiggest(const int& N, const int& M)
{
	int	res(0);

	for (int first(0); first < (N * M) - 2; ++first)
	{
		const int	first_x = first % M;
		const int	first_y = first / M;
		if (map[first_y][first_x] != 0)
			continue ;
		for (int second(first + 1); second < (N * M) - 1; ++second)
		{
			const int	second_x = second % M;
			const int	second_y = second / M;
			if (map[second_y][second_x] != 0)
				continue ;
			for (int third(second + 1); third < (N * M); ++third)
			{
				const int	third_x = third % M;
				const int	third_y = third / M;
				if (map[third_y][third_x] != 0)
					continue ;
				const int	tmp = buildColumn(first_x, first_y, second_x, second_y, third_x, third_y);
				res = res > tmp ? res : tmp;
			}
		}
	}
	return (res);
}

int	main()
{
	cin >> N >> M;

	for (int i(0); i < N; ++i)
	{
		for (int k(0); k < M; ++k)
		{
			cin >> map[i][k];
			if (map[i][k] == 2)
			{
				virus_pos.push(make_pair(i, k));
			}
		}
	}
	int	res = findBiggest(N, M);
	cout << res;
}
