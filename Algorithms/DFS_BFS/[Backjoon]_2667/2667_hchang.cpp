/*
	백준 주소 : https://www.acmicpc.net/problem/2667
	난이도 : 실버1
*/

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::string > arr;
std::vector<std::vector<bool> > isVisted;
std::vector<int> res;

void	dfs(int num)
{

}

int main()
{
	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < num; i++)
	{
		for (int i = 0; i < num; i++)

	}

	dfs(num);

	std::cout << res.size();
	std::sort(res.begin(), res.end());
	for (int i = 0 ; i < res.size(); i++)
		std::cout << res[i] << std::endl;
}