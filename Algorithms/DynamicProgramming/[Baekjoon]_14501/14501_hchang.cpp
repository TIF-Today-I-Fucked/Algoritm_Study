/*
	백준 주소 : https://www.acmicpc.net/problem/14501
	난이도 : 실버3
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int			num;
	std::cin >> num;

	std::vector<std::pair<int, int> >	v;
	std::vector<int>					res;

	for (int i = 0; i < num; i++)
	{
		std::pair<int, int> tmp;
		std::cin >> tmp.first >> tmp.second;
		v.push_back(tmp);
	}

	int idx, tmp;
	for (int i = 0; i < num; i++)
	{
		tmp = 0;
		idx = i;
		while(idx < num)
		{
			if (idx + v[idx].first > num)
				break;
			tmp += v[idx].second;
			idx += v[idx].first;
			std::cout << "tmp : " << tmp  << " idx : " << idx << std::endl;
		}
		res.push_back(tmp);
	}
	std::sort(res.begin(), res.end());
	std::cout << res[num - 1];
}