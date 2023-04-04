/*
	백준 주소 : https://www.acmicpc.net/problem/1912
	난이도 : 실버2
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int num, tmp;
    std::vector<int> v;
    int res;

    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::cin >> tmp;
        v.push_back(tmp);
    }

    res = v[0];
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += v[i];
        res = std::max(res, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    std::cout << res;
}
