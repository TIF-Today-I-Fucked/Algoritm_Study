/*
	백준 주소 : https://www.acmicpc.net/problem/1780
*/

#include <iostream>

int main()
{
	int n;
	int **arr;

	
	std::cin >> n;
	arr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			std::cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++)
		delete [] arr[i];
	delete [] arr;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		std::cout << arr[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	
}