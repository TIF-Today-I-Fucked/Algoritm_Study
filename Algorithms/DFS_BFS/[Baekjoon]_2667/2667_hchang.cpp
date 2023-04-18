/*
	백준 주소 : https://www.acmicpc.net/problem/2667
	난이도 : 실버1
	문제 이름 : 단지번호붙이기
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 25

std::vector<std::string>	map;
bool						visited[MAX][MAX];
int							num;
int							m_x[4] = {1, -1, 0, 0};
int							m_y[4] = {0, 0, 1, -1};

int	dfs(int x, int y, int& res)
{
	if (x < 0 || x >= num || y < 0 || y >= num || visited[y][x] == true || map[y][x] == '0')
		return res;
	res++;
	visited[y][x] = true;
	for (int i = 0 ; i < 4; i++)
		dfs(m_x[i] + x, m_y[i] + y, res);
	return res;

}

int main()
{
	std::vector<int>	res;
	int					tmp_res(0);
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		map.push_back(tmp);
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (map[i][j] == '1' && visited[i][j] == false)
			{
				res.push_back(dfs(j, i, tmp_res));
				tmp_res = 0;
			}
		}
	}

	std::sort(res.begin(), res.end());
	std::cout << res.size() << std::endl;
	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << std::endl;
	}
}