#include <iostream>

unsigned long func(int start_num, int n);

int main()
{
    int n;

    std::cin >> n;

    std::cout << func(0, n) << std::endl;
}

unsigned long func(int start_num, int n) {
    int res = 0;
    if (n == 1)
        return (10 - start_num);
    for (int i = start_num ; i < 10 ; i++)
    {
        res += func(i , n - 1) % 10007;
    }
    return (res);
}