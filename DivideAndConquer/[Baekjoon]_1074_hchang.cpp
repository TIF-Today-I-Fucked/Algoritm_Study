/*
	백준 주소 : https://www.acmicpc.net/problem/1074
*/

#include <iostream>
#include <cmath>

int	square(int n, int a, int b)
{
	//std::cout << "=================================\n";
	//std::cout << n << a << b << std::endl;
	if ( a == 0 && b == 0)
		return 1;
	else if ( a == 0 && b == 1)
		return 2;
	else if ( a == 1 && b == 0)
		return 3;
	else if ( a == 1 && b == 1)
		return 4;
	
	if (a >= pow(2, n - 1) && b >= pow(2, n - 1))
		return ((pow(2, (n - 1) * 2) * 3) + square(n - 1, a - pow(2, n - 1), b - pow(2, n - 1)));
	else if (a >= pow(2, n - 1))
		return (pow(2, (n - 1) * 2) * 2) + square(n - 1, a - pow(2, n - 1) , b);
	else if (b >= pow(2, n - 1))
		return (pow(2, (n - 1) * 2)) + square(n, a , b - pow(2, n - 1));
	else
		return square(n - 1, a, b);

}

int main()
{
	int n, a, b;
	std::cin >> n >> a >> b;

	std::cout << square(n, a, b) - 1;
}