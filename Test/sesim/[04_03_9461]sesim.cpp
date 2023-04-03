#include <algorithm>
#include <iostream>
#include <vector>

void	findPadban(std::vector<unsigned long>& mem, const int& max)
{
	int	i(0);
	for (; i < 5; ++i)
	{
		if (i < 3)
			mem.push_back(1);
		else
			mem.push_back(2);
	}
	for (; i < max; ++i)
	{
		mem.push_back(mem[i - 1] + mem[i - 5]);
	}
}

int	main()
{
	int	input;
	std::cin >> input;
	std::vector<int>	val(input);

	for (int i(0); i < input; ++i)
	{
		std::cin >> val.at(i);
	}
	int	max = std::max_element(val.begin(), val.end()) - val.begin();
	std::vector<unsigned long>	mem;
	findPadban(mem, val[max]);
	for (int i(0); i < input; ++i)
	{
		std::cout << mem[val[i] - 1] << std::endl;
	}
}