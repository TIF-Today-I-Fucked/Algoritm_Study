/*
	백준 주소 : https://www.acmicpc.net/problem/2178
	난이도 : 실버1
	문제 이름 : 미로 찾기
*/

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace	std;

queue<pair<int, int> >	q;
vector<string>			map;
bool					visited[101][101];

int	bfs(const int& y, const int& x)
{
	q.push(make_pair(0, 0));
	int	res(1);

	while (!q.empty())
	{
		int	size = q.size();

		while (size--)
		{
			const int	cur_x = q.front().second;
			const int	cur_y = q.front().first;

			if (cur_x == x && cur_y == y)
				return res;
			visited[cur_y][cur_x] = true;
			if (cur_y + 1 <= y && !visited[cur_y + 1][cur_x] && map[cur_y + 1][cur_x] == '1')
			{
				visited[cur_y + 1][cur_x] = true;
				q.push(make_pair(cur_y + 1, cur_x));
			}
			if (cur_x + 1 <= x && !visited[cur_y][cur_x + 1] && map[cur_y][cur_x + 1] == '1')
			{
				visited[cur_y][cur_x + 1] = true;
				q.push(make_pair(cur_y, cur_x + 1));
			}
			if (cur_y - 1 >= 0 && !visited[cur_y - 1][cur_x] && map[cur_y - 1][cur_x] == '1')
			{
				visited[cur_y - 1][cur_x] = true;
				q.push(make_pair(cur_y - 1, cur_x));
			}
			if (cur_x - 1 >= 0 && !visited[cur_y][cur_x - 1] && map[cur_y][cur_x - 1] == '1')
			{
				visited[cur_y][cur_x - 1] = true;
				q.push(make_pair(cur_y, cur_x - 1));
			}
			q.pop();
		}
		res++;
	}
	return (res);
}

int	main()
{
	int	y, x;
	cin >> y >> x;

	for (int i(0); i < y; ++i)
	{
		string	line;
		cin >> line;
		map.push_back(line);
	}
	cout << bfs(y - 1, x - 1);
}