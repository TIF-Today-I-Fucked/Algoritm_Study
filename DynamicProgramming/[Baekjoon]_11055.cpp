/*
	백준 주소 : https://www.acmicpc.net/problem/11055
	난이도 : 실버2
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/*
	예시 : 1 100 2 50 60 3 5 6 7 8
	1 100
	1 2 50 60 -> 113
	1 2 3 5 6 7 8
*/
int increasing_num(std::vector<int> &v, int num)
{
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