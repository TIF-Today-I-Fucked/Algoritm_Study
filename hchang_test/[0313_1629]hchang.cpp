#include <iostream>
#include <vector>

long long pwr(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a % c;

	if (b % 2 == 0)
		return (((pwr(a, b / 2, c) % c) * (pwr(a, b / 2, c) % c)) % c);
	else
		return (((pwr(a, 1, c) % c) * (pwr(a, b - 1, c) % c)) % c);
}

int main()
{
	long long a, b, c;
	std::cin >> a >> b >> c;

	std::cout << pwr(a, b, c);
}