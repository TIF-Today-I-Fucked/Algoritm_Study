/*
	백준 주소 : https://www.acmicpc.net/problem/1904
	난이도 : 실버3
*/

#include <iostream>
#include <vector>

int main()
{
    int num;
    std::cin >> num;
    std::vector<unsigned long long> v(1000000);
    
    v[0] = 1;
    v[1] = 2;
    for (int i = 2; i < num; i++)
    {
        v[i] = ((v[i - 1] % 15746) + (v[i - 2] % 15746)) % 15746;
    }

    std::cout << v[num - 1];
}
