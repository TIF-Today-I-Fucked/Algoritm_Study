/*
	백준 주소 : https://www.acmicpc.net/problem/11727
	난이도 : 실버3
*/

#include <iostream>
#include <vector>
#include <algorithm>

void	fibonacci_count(int n, std::vector<int>& zero, std::vector<int>& one)
{
	zero.push_back(1);
	one.push_back(0);
	zero.push_back(0);
	one.push_back(1);
	for (std::size_t i(2); i <= n; ++i)
	{
		zero.push_back(zero.at(i - 1) + zero.at(i - 2));
		one.push_back(one.at(i - 1) + one.at(i - 2));
	}
}

int main()
{
	std::vector<int>	zero;
	std::vector<int>	one;
	std::vector<int>	res;
	int	num;
	int	tmp;
	std::cin >> num;
	for (int i(0); i < num; ++i)
	{
		std::cin >> tmp;
		res.push_back(tmp);
	}
	int pos = std::max_element(res.begin(), res.end()) - res.begin();
	fibonacci_count(res[pos], zero, one);
	for (std::size_t i(0); i < num; ++i)
	{
		std::cout << zero.at(res[i]) << " " << one.at(res[i]) << "\n";
	}
}