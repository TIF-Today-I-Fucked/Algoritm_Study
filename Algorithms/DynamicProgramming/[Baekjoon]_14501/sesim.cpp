#include <algorithm>
#include <iostream>
#include <vector>

int	findMaxPay(const int& input, std::vector<std::pair<int, int> >& inary)
{
	int	res;
	std::vector<int>	mem(input);

	for (int i(0); i < input; ++i)
	{
		res = 0;
		for (int k(i); k < input;)
		{
			if (k + inary.at(k).first <= input)
				res += inary.at(k).second;
			k += inary.at(k).first;
			std::cout << "================\n";
			std::cout << k << "  " << res << std::endl;
		}
		mem.push_back(res);
	}
	const int	max = std::max_element(mem.begin(), mem.end()) - mem.begin();
	const int	ans = mem[max];
	return (ans);
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