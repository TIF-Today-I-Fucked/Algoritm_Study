#include <iostream>

int func(int n)
{
	int num[3] = {0, 1, 1};

	if (n == -1)
		return 1;
	else if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
	{
		for (int i = 2 ; i < n ; i++)
		{
			num[0] = num[1];
			num[1] = num[2];
			num[2] = num[0] + num[1];
		}
		return num[2];
	}
}

int main()
{
	int NumberOfCase;
	std::cin >> NumberOfCase;

	int num;
	for (int i = 0 ; i < NumberOfCase ; ++i)
	{
		std::cin >> num;
		std::cout << func(num - 1) << " " << func(num) << "\n";
	}
}