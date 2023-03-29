/*
	백준 주소 : https://www.acmicpc.net/problem/10844
	난이도 : 실버1
*/

#include <iostream>
#include <vector>


int main()
{
	int num;

	std::cin >> num;
	std::vector<std::vector<unsigned long long> > arr;

	std::vector<unsigned long long> tmp = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	arr.push_back(tmp);
	tmp = {1, 2, 2, 2, 2, 2, 2, 2, 2, 1};
	arr.push_back(tmp);

	//std::cout << "=======================\n";
	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << arr[1][i] << " ";
	//}
	//std::cout << "\n=======================\n";

	for (int i = 2; i < num; i++)
	{
		std::vector<unsigned long long> tmp(0);
		for (int j = 0; j < 10;j++)
		{
			if (j == 9)
			{
				tmp.push_back(arr[i - 1][8] % 1000000000);
			}
			else if (j == 0)
			{
				tmp.push_back(arr[i - 1][1] % 1000000000);
			}
			else
			{
				tmp.push_back((arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000);
			}
		}
		arr.push_back(tmp);
	}

	int res(0);
	for (int i = 1 ; i < 10; i++)
	{
		res = (res + arr[num - 1][i]) % 1000000000;
	}
	std::cout << res % 1000000000;

}