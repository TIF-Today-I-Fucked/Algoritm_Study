/*
	백준 주소 : https://www.acmicpc.net/problem/11726
	난이도 : 실버3
*/

#include <iostream>
#include <vector>

unsigned long long	tile(unsigned long long num)
{
	std::vector<unsigned long long> v;
	int idx(0);
	v.push_back(0);

	while (++idx <= num)
	{
		if (idx == 1)
		{
			v.push_back(1);
			continue;
		}
		else if (idx == 2)
		{
			v.push_back(2);
			continue;
		}
		v.push_back((v[idx - 1] + v[idx - 2]) % 10007);
	}
	return v[idx - 1];
}

int main()
{
	int	num;
	std::cin >> num;
	std::cout << tile(num);
}