#include <algorithm>
#include <iostream>
#include <vector>

int	findBiggest(std::vector<int>& val, const int& input)
{
	std::vector<int>	mem;

	if (input == 1)
		return val[0];
	else if (input == 2)
		return val[0] + val[1];
	mem.push_back(val[0]);
	mem.push_back(val[0] + val[1]);
	// mem.push_back(std::max<int>(val[0] + val[1], val[1] + val[2]));
	for (int i(2); i < input; ++i)
	{
		int tmp = std::max<int>(mem[i - 3] + val[i - 1], mem[i - 2]);
		tmp = std::max<int>(mem[i - 1], tmp + val.at(i));
		mem.push_back(tmp);
	}
	return mem[input - 1];
}

int	main()
{
	int	input;
	std::cin >> input;
	std::vector<int>	val(input);
	for (int i(0); i < input; ++i)
	{
		std::cin >> val[i];
	}
	std::cout << findBiggest(val, input);
}