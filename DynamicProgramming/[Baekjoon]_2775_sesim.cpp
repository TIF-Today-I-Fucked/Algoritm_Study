/*
	백준 주소 : https://www.acmicpc.net/problem/11727
	난이도 : 실버3
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


typedef std::vector<int>	apart;
typedef std::vector<std::pair<int, int> >	val;

int	findPerson(int floor, int n)
{
	apart			res;
	unsigned int	i(0);
	unsigned int	k(0);

	for (; i < n; ++i)
	{
		res.push_back(i + 1);
	}
	for (i = 1; i <= floor; ++i)
	{
		for (k = 0; k < n; ++k)
		{
			if (k == 0)
			{
				res.push_back(1);
			}
			else
			{
				res.push_back(res.at(i * n + k - 1) + res.at((i - 1) * n + k));
			}
		}
	}
	return (res.at((i - 1) * n + k - 1));
}

int main()
{
	val			res;
	int	num;
	int	tmp1;
	int	tmp2;

	std::cin >> num;
	for (int i(0); i < num; ++i)
	{
		std::cin >> tmp1 >> tmp2;
		res.push_back(std::make_pair(tmp1, tmp2));
	}
	for (std::size_t i(0); i < num; ++i)
	{
		std::cout << findPerson(res.at(i).first, res.at(i).second) << "\n";
	}
}
