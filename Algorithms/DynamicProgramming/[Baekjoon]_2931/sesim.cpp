#include <iostream>
#include <vector>

unsigned long	findFib(const int& input)
{
	std::vector<unsigned long>	val;
	val.push_back(1);
	val.push_back(1);
	for (int i(2); i < input; ++i)
	{
		val.push_back(val[i - 2] + val[i - 1]);
	}
	return (val[input - 1]);
}

int	main()
{
	int	input;
	std::cin >> input;

	std::cout << findFib(input);
}