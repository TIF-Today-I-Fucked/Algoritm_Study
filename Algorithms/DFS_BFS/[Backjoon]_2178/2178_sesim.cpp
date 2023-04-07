/*
	백준 주소 : https://www.acmicpc.net/problem/2178
	난이도 : 실버1
	문제 이름 : 미로 찾기
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace	std;

queue<pair<int, int> >	q;
bool					visited[101][101];
int						imap[101][101];
int						res(1);

void	shortestWay(const int& n, const int& m, const vector<string>& map)
{
	if (q.empty() || (q.front().first == n - 1 && q.front().second == m - 1))
	{
		imap[q.front().first][q.front().second] = res;
		return ;
	}
	const int	x = q.front().second;
	const int	y = q.front().first;

	const int	up = y - 1;
	const int	down = y + 1;
	const int	left = x - 1;
	const int	right = x + 1;

	if ((down >= 0 && down < n) && (x >= 0 && x < m) && map[down][x] == '1' && !visited[down][x])
	{
		res = imap[y][x] + 1;
		std::cout << "1 " << y << " down  : " << down << " before res : " << imap[y][x] << " after res : " << res << std::endl;
		imap[down][x] = res;
		visited[down][x] = true;
		q.push(make_pair(down, x));
	}
	if ((y >= 0 && y < n) && (right >= 0 && right < m) && map[y][right] == '1' && !visited[y][right])
	{
		std::cout << "2 " << y << " down  : " << down << " before res : " << imap[y][x] << " after res : " << res << std::endl;
		res = imap[y][x] + 1;
		imap[y][right] = res;
		visited[y][right] = true;
		q.push(make_pair(y, right));
	}
	if ((y >= 0 && y < n) && (left >= 0 && left < m) && map[y][left] == '1' && !visited[y][left])
	{
		std::cout << "3 " << y << " down  : " << down << " before res : " << imap[y][x] << " after res : " << res << std::endl;
		res = imap[y][x] + 1;
		imap[y][left] = res;
		visited[y][left] = true;
		q.push(make_pair(y, left));
	}
	if ((up >= 0 && up < n) && (x >= 0 && x < m) && map[up][x] == '1' && !visited[up][x])
	{
		std::cout << "4 " << y << " down  : " << down << " before res : " << imap[y][x] << " after res : " << res << std::endl;
		res = imap[y][x] + 1;
		imap[up][x] = res;
		visited[up][x] = true;
		q.push(make_pair(up, x));
	}
	q.pop();
	shortestWay(n, m, map);
}

int	main()
{
	int	n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			imap[i][j] = 1;
		}
	}
//std::cout << "=============================\n";
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			//std::cout << visited[i][j] << " ";
//			std::cout << imap[i][j] << " ";

//		}
//		std::cout << std::endl;
//	}
//	std::cout << "============================\n";
	vector<string>	map;
	for (int i(0); i < n; ++i)
	{
		string	line;
		cin >> line;
		map.push_back(line);
	}
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	shortestWay(n, m, map);
	//cout << "============\n";

	std::cout << "=============================\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//std::cout << visited[i][j] << " ";
			std::cout << imap[i][j] << " ";

		}
		std::cout << std::endl;
	}
	std::cout << "=============================\n";
	cout << imap[n - 1][m - 1];
}