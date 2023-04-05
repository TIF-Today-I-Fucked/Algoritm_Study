#include <iostream>

int main()
{
	int num;
	int tmp(0);
	unsigned long long arr[101] = {0, };
	unsigned long long res[101] = {0, };

	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::cin >> arr[i];
		tmp = arr[i] > tmp ? arr[i] : tmp;
	}
	
	res[0] = 1; res[1] = 1; res[2] = 1; res[3] = 2; res[4] = 2;

	for (int i = 5; i < tmp; i++)
	{
		if (res[i] != 0)
			continue;
		res[i] = res[i - 1] + res[i - 5];
	}

	for (int i = 0; i < num; i++)
	{
		std::cout << res[arr[i] - 1] << std::endl;
	}
}