#include <iostream>
#include <cstring>

void	printRec(int *res)
{
	std::cout << res[0] << "\n" << res[1] << "\n" << res[2];
}

bool	checkRec(int **map, int size, int x, int y)
{
	int pos = map[y][x];
	for (size_t i(y); i < y + size; ++i)
	{
		for (size_t j(x); j < x + size; ++j)
		{
			if (map[i][j] != pos)
				return false;
		}
	}
	return true;
}

void	findRec(int **map, int *res, int size, int x, int y)
{
	if (size < 1)
		return ;
	if (checkRec(map, size, x, y))
	{
		res[map[y][x]]++;
	}
	else
	{
		for (size_t i(0); i < 3; ++i)
		{
			for (size_t j(0); j < 3; ++j)
				findRec(map, res, (size / 3), x + ((size / 3) * j), y + ((size / 3) * i));
		}
	}
}

int	main()
{
	int	size;
	int **map;
	int	res[3];
	bzero(&res, sizeof(res));
	std::cin >> size;
	map = new int*[size];
	for (size_t i(0); i < size; ++i)
	{
		map[i] = new int[size];
		for (size_t j(0); j < size; ++j)
		{
			std::cin >> map[i][j];
			map[i][j]++;
		}
	}
	findRec(map, res, size, 0, 0);
	printRec(res);
	for (size_t i(0); i < size; ++i)
		delete[] map[i];
	delete[] map;
}