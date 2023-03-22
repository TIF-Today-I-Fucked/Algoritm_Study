/*
	백준 주소 : https://www.acmicpc.net/problem/2579
	난이도 : 실버3
*/

#include <iostream>
#include <algorithm>

int main() 
{
	bool	flag(false);
	int		num;
	int 	arr[302] = {0, };
	int 	res[302] = {0, };
	std::cin >> num;

	for (int i = 0; i < num; i++)
		std::cin >> arr[i];

	res[num - 1] = arr[num - 1];
	res[num - 2] = arr[num - 2];
	for (int i = num - 3; i > 0; i--)
	{
		res[i] = std::max(res[i + 1], res[i + 2] + arr[i]);
	}
	//std::cout << "===================================\n";
	//for (int i = 0; i < num; i++)
	//	std::cout << res[i] << std::endl;	
	//std::cout << "===================================\n";
	if (num < 4)
	{
		if (num == 3)
		{
			std::cout << std::max((arr[2] + arr[0]), (arr[2] + arr[1]));
			return 1;
		}
	}	
	std::cout << arr[0] + res[1];
}