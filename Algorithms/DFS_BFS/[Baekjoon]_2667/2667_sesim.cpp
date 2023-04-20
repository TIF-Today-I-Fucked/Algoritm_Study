#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;
vector<string>	map;
bool	visited[25][25];
int	N;
int	num_of_house;

void	dfs(const int& x, const int& y)
{
	visited[y][x] = true;
	++num_of_house;

	if (y + 1 < N && !visited[y + 1][x] && map[y + 1][x] == '1')
		dfs(x, y + 1);
	if (x + 1 < N && !visited[y][x + 1] && map[y][x + 1] == '1')
		dfs(x + 1, y);
	if (y > 0 && !visited[y - 1][x] && map[y - 1][x] == '1')
		dfs(x, y - 1);
	if (x > 0 && !visited[y][x - 1] && map[y][x - 1] == '1')
		dfs(x - 1, y);
}

int	main()
{
	cin >> N;
	vector<int>	houses;
	for (int i(0); i < N; ++i)
	{
		string	tmp;
		cin >> tmp;
		map.push_back(tmp);
	}
	for (int i(0); i < N; ++i)
	{
		for (int k(0); k < N; ++k)
		{
			if (!visited[i][k] && map[i][k] == '1')
			{
				dfs(k, i);
				houses.push_back(num_of_house);
				num_of_house = 0;
			}
		}
	}
	const int	size = houses.size();
	sort(houses.begin(), houses.end());
	cout << size << "\n";
	for (int i(0); i < size; ++i)
	{
		cout << houses.at(i) << "\n";
	}
}