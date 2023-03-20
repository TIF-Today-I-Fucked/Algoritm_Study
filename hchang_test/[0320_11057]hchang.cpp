#include <iostream>
#include <vector>

int increasing_num(int num)
{
	int arr[num][10];

	for (int i = 0; i < 10; i++)
		arr[0][i] = i + 1;
	
	for (int i = 1;i < num ; i++)
	{
		for (int j = 0; j < 10;j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
				continue;
			}
			arr[i][j] = ((arr[i - 1][j]) % 10007 + (arr[i][j - 1]) % 10007) % 10007;
		}
	}
	return arr[num - 1][9];
}

int main()
{
	int num;

	std::cin >> num;
	std::cout << increasing_num(num);
}