/*
	백준 주소 : https://www.acmicpc.net/problem/9095
	난이도 : 실버3
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// unsigned long long	orderNum(int n)
// {
// 	std::vector<unsigned long long>	arr;
// 	size_t i(0);
// 	for (; i < 10; ++i)
// 		arr.push_back(10 - i);
// 	unsigned long long	idx = 10 * (n - 1);
// 	unsigned long long	res(arr[0]);
// 	i = 1;
// 	for (; i < idx; ++i)
// 	{
// 		if (i % 10 == 0)
// 		{
// 			arr.push_back(res);
// 			std::cout << "idx : " << i << " val : " << arr[i] << std::endl;
// 			continue ;
// 		}
// 		if (i < 10)
// 		{
// 			res += arr[i];
// 		}
// 		else
// 		{
// 			// unsigned long long	before_val = arr[i - 11] > 10007 ? (arr[i - 1] % 10007) : arr[i - 1];
// 			// arr.push_back(before_val - arr[i - 11] % 10007);
// 			arr.push_back(arr[i - 1] - arr[i - 11]);
// 			res += (arr[i] % 10007);
// 		}
// 		std::cout << "idx : " << i << " val : " << arr[i] << std::endl;
// 	}
// 	return (res % 10007);
// }

long long	orderNum(int n)
{
	std::vector<long long>	arr;
	size_t i(0);
	for (; i < 10; ++i)
		arr.push_back(10 - i);
	long long	idx = 10 * (n - 1);
	long long	res(arr[0]);
	i = 1;
	for (; i < idx; ++i)
	{
		if (i % 10 == 0)
		{
			arr.push_back(res);
			// std::cout << "idx : " << i << " val : " << arr[i] << std::endl;
			continue ;
		}
		if (i < 10)
		{
			res += arr[i];
		}
		else
		{
			long long	sub_val = (arr[i - 1] % 10007) - (arr[i - 11] % 10007);
			sub_val = sub_val > 0 ? sub_val : sub_val + 10007;
			arr.push_back(sub_val % 10007);
			res += (arr[i]);
		}
		// std::cout << "idx : " << i << " val : " << arr[i] << std::endl;
	}
	// std::cout << "====================\n";
	// std::cout << "res : " << res << std::endl;
	return (res % 10007);
}

int	main()
{
	int	n;
	std::cin >> n;
	std::cout << orderNum(n);
}