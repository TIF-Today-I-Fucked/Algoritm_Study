#include <iostream>
#include <vector>

int main()
{
    int count;

    std::cin >> count;

    if (count == 1) {
        std::cout <<  "1" << std::endl;
        return 0;
    }
    if (count == 2)
    {
        std::cout <<  "3" << std::endl;
        return 0;
    }
    
    std::vector<int> ways(count);
    ways[0] = 1;
    ways[1] = 3;


    for (int i = 2; i < count ; i++ )
    {
        ways[i] = (ways[i - 1] + 2 * ways[i - 2]) % 10007;
    }
    std::cout <<  ways[count - 1] << std::endl;
    return 0;
}