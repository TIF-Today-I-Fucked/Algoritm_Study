#include <atomic>
#include <iostream>

unsigned long long fastPow(unsigned long long res, int to_pow, const int& to_mod)
{
	if (to_pow == 1)
		return (res % to_mod);
	else if (to_pow == 0)
		return (1);
	if (to_pow % 2 == 1)
		return (((res % to_mod) * (fastPow(res, to_pow - 1, to_mod) % to_mod)) % to_mod);
	unsigned long long	half = fastPow(res, to_pow / 2, to_mod) % to_mod;
	return ((half * half) % to_mod);
}

int	main()
{
	unsigned long long	res;
	int	to_pow;
	int	to_mod;

	std::cin >> res >> to_pow >> to_mod;
	std::cout << fastPow(res, to_pow, to_mod);
}