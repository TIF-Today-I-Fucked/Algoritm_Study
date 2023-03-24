/*
	백준 주소 : https://www.acmicpc.net/problem/1932
	난이도 : 실버3
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num, tmp;
	std::vector<std::vector<int> >	v;
	std::vector<std::vector<int> >	res;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::vector<int> tmp_v;
		for (int j = 0; j <= i; j++)
		{
			std::cin >> tmp;
			tmp_v.push_back(tmp);
		}
		v.push_back(tmp_v);
	}

	res.push_back(v[0]);
	for (size_t i = 1; i < num; i++)
	{
		std::vector<int> tmp_res;
		for (size_t j = 0; j < v[i].size(); j++)
		{
			if (j == 0)
			{
				tmp_res.push_back(res[i - 1][0] + v[i][0]);
				continue;
			}
			else if (j == v[i].size() - 1)
			{
				tmp_res.push_back(res[i - 1][j - 1] + v[i][j]);
				continue;
			}
			int num1 = v[i][j] + res[i - 1][j - 1];
			int num2 = v[i][j] + res[i - 1][j];
			tmp_res.push_back(std::max(num1, num2));
		}
		res.push_back(tmp_res);
	}

	int finalres(res[num - 1][0]);
	for (size_t i = 1; i < res[num - 1].size(); i++)
	{
		if (finalres < res[num - 1][i])
			finalres = res[num - 1][i];
	}
	std::cout << finalres;
}