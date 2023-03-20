#include <iostream>
#include <vector>

long long pwr(long long a, long long b, long long c)
{
	//std::cout << " a " << a << " b   " << b << " c : " << c << std::endl;
	if (b == 0)
		return 1;
	if (b == 1)
		return a % c;
	
	if (b % 2 == 0)
		return ((pwr(a, b / 2, c) % c) * (pwr(a, b / 2, c) % c));
	else
		return ((a % c) * (pwr(a, b - 1, c) % c));
}

int main()
{
	long long a, b, c;
	std::cin >> a >> b >> c;
	
	std::cout << pwr(a, b, c) % c;
}