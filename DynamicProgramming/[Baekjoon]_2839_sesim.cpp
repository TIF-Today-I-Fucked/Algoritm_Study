/*
	백준 주소 : https://www.acmicpc.net/problem/11727
	난이도 : 실버3
*/

#include <iostream>
#include <vector>

int	sugarDeliver(int num)
{
	int	res(0);
	
	while (num > 2)
	{
		if (num % 5 == 0)
		{
			num -= 5;
			res++;
		}
		else
		{
			num -= 3;
			res++;
		}
	}
	if (num != 0)
		return (-1);
	return (res);
}

int main()
{
	int	num;
	std::cin >> num;
	std::cout << sugarDeliver(num);
}