#include <iostream>
#include <vector>

unsigned long	Longest(std::vector<int>& arr, const int& input)
{
	unsigned long				res(0);
	std::vector<unsigned long>	mem(input);

	for (int i(0); i < input; ++i)
	{
		mem[i] = 1;
		for (int j(i - 1); j >= 0; --j)
		{
			if (arr[i] > arr[j])
			{
				mem[i] = std::max<unsigned long>(mem[i], mem[j] + 1);
			}
		}
		res = res > mem[i] ? res : mem[i];
	}
	return (res);
}

int	main()
{
	int	input;
	std::cin >> input;
	std::vector<int>	v_input(input);
	for (int i(0); i < input; ++i)
	{
		std::cin >> v_input.at(i);
	}
	std::cout << Longest(v_input, input);
}