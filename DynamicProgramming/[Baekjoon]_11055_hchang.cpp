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
	int res(0), tmp(0), cmp(0);
	int v_size = v.size();

	for(int i(0); i < v_size - 2; ++i)
	{
		cmp = v[i];
		res = v[i];
		for (int j(i + 1); j < v_size - 1; ++j)
		{
			tmp = v[i];
			if (cmp <= v[j])
			{
				tmp += v[j];
				cmp = v[j];
			}
			for (int k(j + 1); k < v_size; ++k)
			{
				if (cmp <= v[k])
				{
					tmp += v[k];
					cmp = v[k];
					std::cout << "v[" << i << "] :  " << v[i] << " || v[" << j << "] :  " << v[j] << " || v[" << k << "] :  " << v[k] << std::endl;
					continue;
				}	
			}
		}
		std::cout << "cmp : " << cmp << " || tmp : " << tmp << " || res : " << res << std::endl;
		std::cout << "===============================\n";
		if (tmp > res)
			res = tmp;
	}
	return res;
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