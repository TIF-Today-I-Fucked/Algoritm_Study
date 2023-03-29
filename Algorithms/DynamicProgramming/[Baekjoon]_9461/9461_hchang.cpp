/*
	백준 주소 : https://www.acmicpc.net/problem/9461
	난이도 : 실버3
*/

#include <iostream>
#include <vector>

int main()
{
	int num;
	int cnt(0);
	unsigned long long arr[101] = {0, };
	unsigned long long res[101] = {0, };
	std::cin >> num;

	res[0] = 1; res[1] = 1; res[2] = 1; res[3] = 2; res[4] = 2;
	for (int i = 0; i < num; i++)
	{
		std::cin >> arr[i];
		cnt = arr[i] > cnt ? arr[i] : cnt;
	}
	for (int i = 5; i < cnt; i++)
		res[i] = res[i - 1] + res[i - 5];

	for (int i = 0; i < num; i++)
	{
		std::cout << res[arr[i] - 1] << std::endl;
	}
}