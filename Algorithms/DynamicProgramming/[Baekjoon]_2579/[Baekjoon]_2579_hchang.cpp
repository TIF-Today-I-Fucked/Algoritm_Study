/*
	문제 이름 : 계단 오르기
	백준 주소 : https://www.acmicpc.net/problem/2579
	난이도 : 실버3
*/

#include <iostream>
#include <algorithm>

int main()
{
	int 				num;
	unsigned long long	arr[301] = {0, };
	unsigned long long	res[301] = {0, };
	
	std::cin >> num;
	for (int i = 1; i <= num; i++)
		std::cin >> arr[i];
	res[1] = arr[1]; res[2] = arr[1] + arr[2];

	for (int i = 3; i <= num; i++)
	{
		res[i] = std::max(arr[i] + arr[i - 1] + res[i - 3], arr[i] + res[i - 2]);
	}	

	std::cout << res[num] << std::endl;
}