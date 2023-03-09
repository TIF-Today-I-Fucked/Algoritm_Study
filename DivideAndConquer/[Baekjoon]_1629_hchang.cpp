#include <iostream>


// ex) a 5 b 4 c 3

// 5 ^ 4 = 625 % 3 = 1
// ((5 ^ 2) +/* (5 ^ 2)) % 3 = 200 % 3 or 10000 % 3 = 2 or 1

// ex) a b c 4 6 5
// 4 ^ 6 = 4096 % 5 => 1
// 4 ^ 3 => 64 + 64 or 64 * 64 ==> 4096

// 64 % 5 => (4 * 4) % 4 = 1



long long	power(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a % c;

	if (b % 2 == 0)
		return (((power(a, b / 2, c) % c) * (power(a, b / 2, c) % c)) % c);
	return (((power(a, b / 2, c) % c) * (power(a, (b / 2) + 1, c) % c)) % c);
}

int main()
{
	long long a, b, c;
	std::cin >> a >> b >> c;

	long long 
	std::cout << power(a, b, c);
}