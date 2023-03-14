/*
	백준 주소 : https://www.acmicpc.net/problem/9095
	난이도 : 실버3
*/

#include <iostream>
#include <vector>
#include <cmath>

unsigned long long	sum(unsigned long long num)
{
	std::vector<unsigned long long> v;
	int idx(-1);
	while (++idx < num)
	{
		if (idx < 3)
		{
			v.push_back((int)pow(2.0, idx));
			continue ;
		}
		v.push_back(v[idx - 1] + v[idx - 2] + v[idx - 3]);
	}
	return v[idx - 1];
}

int main()
{
	int	num;
	std::vector<int> res;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		int	tmp;
		std::cin >> tmp;
		res.push_back(sum(tmp));
	}
	for (int i = 0; i < num; i++)
	{
		std::cout << res[i];
		if (i != num - 1)
			std::cout << std::endl;
	}
}