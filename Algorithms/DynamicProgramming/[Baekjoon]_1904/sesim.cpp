#include <iostream>
#include <vector>

unsigned long	findTile(const int& input)
{
	std::vector<unsigned long>	mem(input);
	mem[0] = 1;
	mem[1] = 2;
	for (int i(2); i < input; ++i)
	{
		mem[i] = ((mem[i - 1] % 15746) + (mem[i - 2] % 15746)) % 15746;
	}
	return mem[input - 1] % 15746;
}

int	main()
{
	int	input;
	std::cin >> input;

	std::cout << findTile(input);
}