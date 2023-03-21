#include <iostream>

unsigned long long	fastPow(const unsigned long long& n, int to_pow, int to_mod)
{
	if (to_pow == 1)
		return n % to_mod;
	else if (to_pow == 0)
		return 1;
	if (to_pow % 2 == 1)
		return (((n % to_mod) * (fastPow(n, to_pow - 1, to_mod) % to_mod)) % to_mod);
	unsigned long long	half = fastPow(n, to_pow / 2, to_mod) % to_mod;
	return ((half * half) % to_mod);
}

int	main()
{
	unsigned long long	n;
	int					to_pow;
	int					to_mod;
	std::cin >> n >> to_pow >> to_mod;
	std::cout << fastPow(n, to_pow, to_mod);
}