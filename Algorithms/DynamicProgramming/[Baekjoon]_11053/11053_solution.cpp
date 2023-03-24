#include <cstddef>
#include <iostream>
#include <vector>

int	findLongest(const std::vector<int>& arr, const int& input)
{
	int	res(0);
	std::vector<int>	memo(input);
	for (int i(0); i < input; ++i)
	{
		memo[i] = 1;
		for (int j(i - 1); j >= 0; --j)
		{
			if (arr[i] > arr[j])
			{
				memo[i] = std::max<int>(memo[i], memo[j] + 1);
			}
		}
		res = std::max<int>(memo[i], res);
	}
	return (res);
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