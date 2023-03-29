#include <iostream>

int main()
{
    int size;
    std::cin >> size;


    int max_length = 1;
    int last = 0;
    int curr = 0;
    for (int i = 0 ; i < size; i++)
    {
        std::cin >> curr;
        if (last < curr)
        {
            i++;
            last = curr;
            max_length = (max_length > i) ? max_length : i;
        }
    }
    std::cout << max_length << std::endl;
}