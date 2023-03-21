/*
	백준 주소 : https://www.acmicpc.net/problem/9095
	난이도 : 실버3
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

long long	orderNum(int n)
{
	long long arr[1001][10] = {0, };
	long long res(0);

	for (int i = 0 ; i < 10; i++)
		arr[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
				continue;
			}
			arr[i][j] = ((arr[i - 1][j] % 10007) + (arr[i][j - 1] % 10007)) % 10007;
		}
	}
	for (int i = 0; i < 10; i++)
		res += arr[n - 1][i];
	return res % 10007;
}

int	main()
{
	int	n;
	std::cin >> n;
	std::cout << orderNum(n);
}