/*
	백준 주소 : https://www.acmicpc.net/problem/11055
	난이도 : 실버2
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int	increasing_num(std::vector<int>& arr, const int& num)
{
	std::vector<int>	memo;
	int	res(0);

	for (int i(0); i < num; ++i)
	{
		memo.push_back(arr[i]);
		for (int j(0); j < i; ++j)
		{
			if (arr[j] < arr[i] && memo[i] < memo[j] + arr[i])
			{
				memo[i] = memo[j] + arr[i];
			}
		}
		res = res < memo[i] ? memo[i] : res;
	}
	return (res);
}

int	main()
{
	std::vector<int>	arr;
	int	num, tmp;
	std::cin >> num;

	for (int i(0); i < num; ++i)
	{
		std::cin >> tmp;
		arr.push_back(tmp);
	}
	std::cout << increasing_num(arr, num);
}