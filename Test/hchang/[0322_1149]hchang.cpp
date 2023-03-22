#include <iostream>
#include <algorithm>

int main()
{
	int num;
	int arr[1001][3] = {0, };
	int res[1001][3] = {0, };
	std::cin >> num;

	for (int i = 0; i < num; i++)
		std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	res[0][0] = arr[0][0];
	res[0][1] = arr[0][1];
	res[0][2] = arr[0][2];
	for (int i = 1; i <= num; i++)
	{
		res[i][0] = std::min(res[i - 1][1], res[i - 1][2]) + arr[i][0];
		res[i][1] = std::min(res[i - 1][0], res[i - 1][2]) + arr[i][1];
		res[i][2] = std::min(res[i - 1][0], res[i - 1][1]) + arr[i][2];
	}

	std::cout << std::min(res[num][0], std::min(res[num][1], res[num][2]));
}