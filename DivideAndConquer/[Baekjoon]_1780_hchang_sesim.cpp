/*
	백준 주소 : https://www.acmicpc.net/problem/1780
*/

#include <iostream>

int map[2200][2200];
int	res[3];

void print_res(void)
{
	std::cout << res[0] << "\n";
	std::cout << res[1] << "\n";
	std::cout << res[2];

}

bool	checkRect(int size, int x, int y)
{
	int	tmp(map[y][x]);
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (tmp != map[i][j])
				return false;
		}
	}
	return true;
}

void	findRect(int size, int x, int y)
{
	if (size < 1)
		return ;
	if (checkRect(size, x, y))
	{
		res[map[y][x]]++;
	}
	else
	{
		for (int i = y; i < y + 3; i++)
			for (int j = x; j < x + 3; j++)
				findRect(size / 3, x + (size / 3) * (j - x), y + (size / 3) * (i - y));
	}
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
			map[i][j]++;
		}
	}
	findRect(n, 0, 0);	
	print_res();
}