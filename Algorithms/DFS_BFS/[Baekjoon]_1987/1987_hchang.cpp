/*
	백준 주소 : https://www.acmicpc.net/problem/1987
	난이도 : 골드4
	문제 이름 : 알파벳
*/

#include <iostream>
#include <algorithm>
#include <vector>

const int			MAX = 20;
int					R, C, res;
std::string			map[MAX];
bool				visited[MAX][MAX];
std::vector<char>	checker;
int					m_x[4] = {1, -1, 0, 0};
int					m_y[4] = {0, 0, 1, -1};

void	dfs(int x, int y, int cnt)
{
	res = cnt > res ? cnt : res;
	for (int i = 0 ; i < 4; i++)
	{
		int cur_x = x + m_x[i];
		int cur_y = y + m_y[i];
		if ((cur_x >= 0 && cur_x < C && cur_y >= 0 && cur_y < R) && std::find(checker.begin(), checker.end(), map[cur_y][cur_x]) == checker.end())
		{
			if (visited[cur_y][cur_x] == false)
			{
				visited[cur_y][cur_x] = true;
				checker.push_back(map[cur_y][cur_x]);
				dfs(cur_x, cur_y, cnt + 1);
				checker.pop_back();
				visited[cur_y][cur_x] = false;
			}
		}
	}


}

int main()
{
	std::cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		std::cin >> map[i];
	}

	visited[0][0] = true;
	checker.push_back(map[0][0]);
	dfs(0, 0, 1);
	std::cout << res << std::endl;

}