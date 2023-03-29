#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0 ; i <=  N / 3 ; i++)
    {
        if ( (2 * i + N) % 5 )
            continue;
        std::cout << (int)((2 * i + N) / 5) << std::endl;
        return 0;
    }
    std::cout << "-1" << std::endl;
}