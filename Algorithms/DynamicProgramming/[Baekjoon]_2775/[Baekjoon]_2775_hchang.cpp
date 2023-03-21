/*
	백준 주소 : https://www.acmicpc.net/problem/1003
	난이도 : 브론즈1
*/

#include <iostream>
#include <vector>

int	apartment(std::pair<int, int>& tmp)
{
	int arr[15][15];

	for (int i = 0; i < tmp.second; i++)
		arr[0][i] = i + 1;
	
	//if (tmp.first == 0)
	//	return arr[tmp.first][tmp.second - 1];
	for (int i = 1; i <= tmp.first; i++)
	{
		for (int j = 0; j < tmp.second ; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
				continue;
			}
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	return arr[tmp.first][tmp.second - 1];
}

int main()
{
	int num;
	std::vector<std::pair<int, int> > arr;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::pair<int , int> tmp;
		std::cin >> tmp.first >> tmp.second;
		arr.push_back(tmp);
	}
	for (int i = 0; i < num; i++)
		std::cout << apartment(arr[i]) << std::endl;
}
