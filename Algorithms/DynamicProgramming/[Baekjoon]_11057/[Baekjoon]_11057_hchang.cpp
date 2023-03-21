/*
	백준 주소 : https://www.acmicpc.net/problem/11057
	난이도 : 실버1
*/

#include <iostream>

long long	ascending_num(int cnt)
{
	if (cnt == 1)
		return 10;
	long long res;

	for (int i = 10; i > 0; i--)
	{
		ascending_num(--cnt);
	}
}

int main()
{
	int	num;
	std::cin >> num;
	std::cout << ascending_num(cnt);
}
