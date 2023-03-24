#include <cstddef>
#include <iostream>
#include <vector>

int	findLongest(const std::vector<int>& arr, const int& input)
{
	std::vector<int>	memo;
	memo.push_back(1);
	for (size_t	i(1); i < input; ++i)
	{
		if (i == 1 && arr[i] > arr[0])
		{
			memo.push_back(2);
			continue ;
		}
		else if (i == 1 && arr[i] <= arr[0])
		{
			memo.push_back(1);
			continue ;
		}
		if (arr[i] > arr[i - 1] && arr[i] > arr[i - 2])
		{
			memo.push_back(memo[i - 1] + 1);
		}
		else
		{
			memo.push_back(std::max<int>(memo[i - 1], memo[i - 2]));
		}
		std::cout << memo.at(i) << std::endl;
	}
	return memo.at(memo.size() - 1);
}

int	main()
{
	int	input;
	std::cin >> input;
	
	std::vector<int>	arr(input);
	for (size_t i(0); i < input; ++i)
	{
		std::cin >> arr[i];
	}
	std::cout << findLongest(arr, input);
}