#include <algorithm>
#include <iostream>
#include <vector>

int	findMaxPay(const int& input, std::vector<std::pair<int, int> >& inary)
{
	int	res(0);

	for (int i(input - 1); i >= 0; ++i)
	{
		
	}
	return (res);
}

int	main()
{
	int	input;
	std::cin >> input;
	std::vector<std::pair<int, int> >	inary(input);

	for (int i(0); i < input; ++i)
	{
		std::cin >> inary.at(i).first >> inary.at(i).second;
	}
	std::cout << findMaxPay(input, inary);
}