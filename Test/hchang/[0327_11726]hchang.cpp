#include <iostream>

int main()
{
	int num;
	int arr[1001] = {0, };

	std::cin >> num;
	arr[0] = 1; arr[1] = 2;

	for (int i = 2; i < num; i++)
		arr[i] = ((arr[i - 1] % 10007) + (arr[i - 2] % 10007)) % 10007;
	
	std::cout << arr[num - 1];
}