#include <iostream>
#include <vector>
#include <cmath>

long long	findTile(int input)
{
	std::vector<long long>	memo;

	for (int i(0); i < input; ++i)
	{
		if (i == 0)
			memo.push_back(1);
		else if (i == 1)
			memo.push_back(3);
		else
		{
			memo.push_back((memo[i - 1] % 10007) + (memo[i - 2] % 10007));
		}
	}
	return (memo[input - 1] % 10007);
}

int	main()
{
	int	input;
	std::cin >> input;
	std::cout << findTile(input);
}