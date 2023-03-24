/*
	백준 주소 : https://www.acmicpc.net/problem/11053
	난이도 : 실버2
*/

#include <iostream>
#include <algorithm>
/*
6
10 20 10 30 20 50
*/

int main()
{
	int arr[1001] = {0, };
	int res[1001] = {0, };
	int num;

	std::cin >> num;
	for (int i = 0; i < num; i++)
		std::cin >> arr[i];
	
	if (num == 2)
	{
		std::cout << (arr[0] < arr[1]) + 1;
		return 0;
	}
	res[1] = arr[1] > arr[0];
	for (int i = 2; i < num; i++)
	{
		if (arr[i] > arr[i - 1] && arr[i] > arr[i - 2])
		{
			res[i] = std::max<int>(res[i - 1], res[i - 2]) + 1;
			std::cout << "what\n";
			continue;
		}
		//else if(arr[i] > arr[i - 1] || arr[i] > arr[i - 2])
		res[i] = std::max<int>(res[i - 1], res[i - 2]);
	}

	std::cout << "======================================\n";
	for (int i = 0; i < num; i++)
		std::cout << res[i] << std::endl;
	std::cout << "======================================\n";

	std::cout << res[num - 1] + 1;
}