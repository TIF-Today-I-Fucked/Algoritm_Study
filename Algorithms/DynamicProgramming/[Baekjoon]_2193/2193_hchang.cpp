/*
	백준 주소 : https://www.acmicpc.net/problem/2193
	난이도 : 실버3
*/

#include <iostream>

int main()
{
    int num;
    unsigned long long arr[91] = {0, };
    std::cin >> num;
    
    arr[1] = 1;
    for (int i = 2; i <= num; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    std::cout << arr[num];
}
