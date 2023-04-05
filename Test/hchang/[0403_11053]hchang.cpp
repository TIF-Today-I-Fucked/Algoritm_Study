#include <iostream>
#include <algorithm>

int main()
{
	int num;
	int tmp(0);
	int arr[1001] = {0, };
	int res[1001] = {0, };

	std::cin >> num;
	for (int i = 0; i < num; i++)
		std::cin >> arr[i];
	
	for (int i = 0; i < num; i++)
	{
		res[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i])
			{
				res[i] = std::max(res[i], res[j] + 1);
			}
		}
		tmp = std::max(tmp, res[i]);
	}
	std::cout << tmp;
}