/*
	백준 주소 : https://www.acmicpc.net/problem/2836
	난이도 : 실버4
*/

#include <iostream>
#include <vector>

void	sugar_box(int num, int res)
{
	if (num < 3)
	{
		res = -1;
		std::cout << res;
		return ;
	}
	if (num % 5 == 0)
	{
		res += num / 5;
		std::cout << res;
		return ;
	}
	while (num > 0)
	{
		num -= 3;
		res++;
		if (num % 5 == 0)
		{
			res += (num / 5);
			std::cout << res;
			return ;
		}
	}
	std::cout << -1;
}

int main()
{
	int num;
	int res(0);
	std::cin >> num;

	sugar_box(num, res);
}
