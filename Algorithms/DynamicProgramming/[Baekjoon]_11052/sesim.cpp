#include <iostream>
#include <vector>

unsigned long	blackCow(const int& n, const std::vector<int>& arr)
{
	std::vector<unsigned long>	mem(n + 1);
	
	for (int i(1); i <= n; ++i)
	{
		for (int j(1); j <= i; ++j)
		{
			mem[i] = std::max<unsigned long>(mem[i], mem[i - j] + arr[j]);
		}
	}
	return mem[n];
}

int	main()
{
	int	n;
	std::cin >> n;
	std::vector<int>	card_pack(n + 1);
	for (int i(1); i <= n; ++i)
	{
		std::cin >> card_pack[i];
	}
	std::cout << blackCow(n, card_pack);
}