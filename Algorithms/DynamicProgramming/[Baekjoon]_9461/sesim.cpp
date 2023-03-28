#include <algorithm>
#include <iostream>
#include <streambuf>
#include <vector>

void	find_biggiest(std::vector<long long>& seq, const int& max)
{
	int i(0);
	for (; i < 5; ++i)
	{
		if (i < 3)
			seq.push_back(1);
		else
			seq.push_back(2);
	}
	for (; i < max; ++i)
	{
		seq.push_back(seq.at(i - 1) + seq.at(i - 5));
	}
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
	int	max = std::max_element(val.begin(), val.end()) - val.begin();
	std::vector<long long>	padovan_seq;
	find_biggiest(padovan_seq, val[max]);
	for (int i(0); i < input; ++i)
	{
		std::cout << padovan_seq[val[i] - 1] << std::endl;
	}
}