#include <iostream>

long Combination(int n, int p)
{
    long res = 1;
    if ((n - p) < p)
        p = (n - p);
    for (int i = 0 ; i < p ; i++)
    {
        res *= (n - i) % 10007;
        res %= 10007;
    }
    for (int i = 0 ; i < p ; i++)
        res /= (1 + i);
    std::cout << n << "C" << p << "=" <<  res  << std::endl;
    return res;
}

int main()
{
    int n;

    std::cin >> n;

    long res = 0;
    int y_max = n / 2;
    int x;
    for (int y = 0 ; y <= y_max ; y++)
    {
        x = n - 2 * y;
        res += Combination(x + y,y) % 10007;
        res %= 10007;
    }
    std::cout << res % 10007<< std::endl;
}