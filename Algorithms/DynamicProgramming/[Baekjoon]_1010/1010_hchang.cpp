/*
	백준 주소 : https://www.acmicpc.net/problem/1010
	난이도 : 실버5
*/

#include <iostream>

int main()
{
	int					num;
	unsigned long long	arr[1001][2];
	unsigned long long	res1;
	unsigned long long	res2;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::cin >> arr[i][0]>> arr[i][1];
		if (arr[i][0] > arr[i][1] - arr[i][0])
			arr[i][0] = arr[i][1] - arr[i][0];
	}

	for (int i = 0; i < num; i++)
	{
		res1 = 1;
		res2 = 1;

		for (int j = arr[i][1]; j > arr[i][1] - arr[i][0] ; j--)
		{
			res1 *= j;
		}
		//std::cout << "res1 " << res1 << std::endl;
		for (int k = arr[i][0]; k >= 1 ; k--)
		{
			res2 *= k;
		}
		//std::cout << "res2 " << res2 << std::endl;
		std::cout << res1 / res2 << std::endl;
	}
	return (0);
}