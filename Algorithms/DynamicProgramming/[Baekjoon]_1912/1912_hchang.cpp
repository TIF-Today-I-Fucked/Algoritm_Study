/*
	백준 주소 : https://www.acmicpc.net/problem/1912
	난이도 : 실버2
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int	num, tmp;
	std::vector<int> v;
	std::vector<int> res;

	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < num; i++)
	{
		std::vector<int> tmp;
		int tmp_num(0), res_tmp(0);
		for (int j = i; j >= 0; j--)
		{
			tmp_num += v[j];
			res_tmp = tmp_num > res_tmp ? tmp_num : res_tmp;
		}
		res.push_back(res_tmp);
	}
	std::sort(res.begin(), res.end());
	std::cout << res[res.size() - 1];
}