#include <vector>
#include <iostream>

int map[2300][2300];
int	result[3];

bool	check_paper(int num, int x, int y)
{
	int first_thing = map[y][x];

	for (int i = y; i < y + num; i++)
	{
		for (int j = x; j < x + num; j++)
		{
			if (first_thing != map[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void	count_paper(int num, int x, int y)
{
	if (num < 1)
		return ;
	if (check_paper(num, x, y))
	{
		result[map[y][x]]++;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				count_paper(num / 3, x + (num / 3) * j, y + (num / 3) * i);
			}
		}
	}
}

int main()
{
	int cnt;

	std::cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			std::cin >> map[i][j];
			map[i][j]++;
		}
	}

	count_paper(cnt, 0, 0);

	std::cout << result[0] << std::endl;
	std::cout << result[1] << std::endl;
	std::cout << result[2];
}