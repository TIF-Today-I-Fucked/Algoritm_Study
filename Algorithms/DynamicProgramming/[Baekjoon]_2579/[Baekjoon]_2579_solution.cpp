#include<iostream>
#include<vector>

int	main()
{
	int	Input;
	std::cin >> Input;
	int	arr[301] = {0, };
	int	res[301] = {0, };

	for (int i(0); i < Input; ++i)
	{
		std::cin >> arr[i];
	}
	res[0] = arr[0];
	res[1] = arr[0] + arr[1];
	res[2] = std::max<int>(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < Input; ++i)
	{
		res[i] = std::max<int>(arr[i - 1] + res[i - 3], res[i - 2]);
		res[i] += arr[i];
	}
	std::cout << res[Input - 1];
}