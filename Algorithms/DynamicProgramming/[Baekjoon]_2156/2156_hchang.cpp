/*
	백준 주소 : https://www.acmicpc.net/problem/2156
	난이도 : 실버1
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int								num;
	std::vector<unsigned long long>	v(10000, 0);
	std::vector<unsigned long long>	res;
	
	std::cin >> num;
	for(int i = 0; i < num; i++)
		std::cin >> v[i];

	res.push_back(0); res.push_back(v[0]); res.push_back(v[0] + v[1]);
	for (int i = 3; i <= num; i++)
	{
		//if (i == 2)
		//{
		//	res.push_back(std::max((v[i] + res[i - 1]), (v[i] + res[i - 2])));
		//	std::cout << "heyy " << res[i] << " what " << v[i] << std::endl;
		//	continue;
		//}
		res.push_back(std::max((v[i - 1] + v[i - 2] +  res[i - 3]), (v[i - 1] + res[i - 2])));
		res[i] = std::max(res[i - 1], res[i]);
	}
	std::cout << res[num];
}
