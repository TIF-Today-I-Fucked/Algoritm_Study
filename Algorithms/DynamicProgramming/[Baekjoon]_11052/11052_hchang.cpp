/*
	백준 주소 : https://www.acmicpc.net/problem/11052
	난이도 : 실버1
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int num, tmp;
	int	arr[1001] = {0, };
	unsigned long long 	res[1001][1001];
    std::cin >> num;
    
	for (int i = 1; i <= num; i++)
		std::cin >> arr[i];

	for (int i = 2; i <= num; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (i % j == 0)
			{
				arr[i] = std::max(arr[i], (i / j) * arr[j]);
			}
			arr[i] = std::max(arr[i], arr[(i - j)] + arr[j]);
		}
	}
	//std::cout << "=======================\n";	
	//for (int i = 0; i <= num; i++)
	//{
	//	std::cout << arr[i] <<  " ";
	//}
	//std::cout << "\n=======================\n";


	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			tmp = num - i;
			if (j == 1)
			{
				res[i][j] = (arr[i] + ((tmp / j) * arr[j])) > res[i - 1][num] ? (arr[i] + ((tmp / j) * arr[j])) : res[i - 1][num];
				continue;
			}	
			res[i][j] = (arr[i] + ((tmp / j) * arr[j])) > res[i][j - 1] ? (arr[i] + ((tmp / j) * arr[j])) : res[i][j - 1];
		}
	}

	//std::cout << "=======================\n";
	//for (int i = 0; i <= num; i++)
	//{
	//	std::cout << i << " : ";
	//	for (int j = 1; j <= num; j++)
	//	{
	//		std::cout << res[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << "=======================\n";

	std::cout << res[num][num];
}
