
/*
	백준 주소 : https://www.acmicpc.net/problem/14502
	난이도 : 골드4
	문제 이름 : 연구실
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define MAX 8
int 	map[MAX][MAX];
int 	tmp_map[MAX][MAX];
int		X, Y;

void	make_two(std::queue<std::pair<int, int> > new_queue)
{
	while (!new_queue.empty())
	{
		int size = new_queue.size();
		while(size--)
		{
			std::pair<int, int> tmp = new_queue.front();
			new_queue.pop();
			if (tmp.first + 1 < X && map[tmp.second][tmp.first + 1] == 0)
			{
				map[tmp.second][tmp.first + 1] = 2;
				new_queue.push(std::make_pair(tmp.first + 1, tmp.second));
			}
			if (tmp.second + 1 < Y && map[tmp.second + 1][tmp.first] == 0)
			{
				map[tmp.second + 1][tmp.first] = 2;
				new_queue.push(std::make_pair(tmp.first, tmp.second+ 1));
			}
			if (tmp.first - 1 >= 0 && map[tmp.second][tmp.first - 1] == 0)
			{
				map[tmp.second][tmp.first - 1] = 2;
				new_queue.push(std::make_pair(tmp.first - 1, tmp.second));
			}
			if (tmp.second - 1 >= 0 && map[tmp.second - 1][tmp.first] == 0)
			{
				map[tmp.second - 1][tmp.first] = 2;
				new_queue.push(std::make_pair(tmp.first, tmp.second - 1));
			}
		}
	}
}

void	mapCopy(void)
{
	for(int i = 0; i < Y; i++)
	{
		for(int j = 0; j < X; j++)
		{
			map[i][j] = tmp_map[i][j];
		}
	}
}

int	countOne(void)
{
	int cnt(0);

	for(int i = 0; i < Y; i++)
	{
		for(int j = 0; j < X; j++)
		{
			if (map[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	std::queue<std::pair<int, int> >	tmp_queue;

	std::cin >> Y >> X;
	
	for(int i = 0; i < Y; i++)
	{
		for(int j = 0; j < X; j++)
		{
			std::cin >> map[i][j];
			tmp_map[i][j] = map[i][j];
			if (map[i][j] == 2)
			{
				tmp_queue.push(std::make_pair(j, i));
			}
		}
	}


	int res(0);
	int a1(0);
	int a2(0);
	int a3(0);
	
	while (a1 < X * Y)
	{
		mapCopy();
		while (map[a1 / X][a1 % X] != 0 && a1 < X * Y)
			a1++;
		a2 = a1 + 1;
		while (a2 < X * Y)
		{
			mapCopy();
			while(map[a2 / X][a2 % X] != 0 && a2 < X * Y)
				a2++;
			a3 = a2 + 1;
			while (a3 < X * Y)
			{
				mapCopy();
				while(map[a3 / X][a3 % X] != 0 && a3 < X * Y)
					a3++;
				map[a1 / X][a1 % X] = 1;
				map[a2 / X][a2 % X] = 1;
				map[a3 / X][a3 % X] = 1;
				make_two(tmp_queue);
				int tmp = countOne();
				res = tmp > res ? tmp : res;
				a3++;
			}
			a2++;
		}
		a1++;
	}
	
	std::cout << res;


}
