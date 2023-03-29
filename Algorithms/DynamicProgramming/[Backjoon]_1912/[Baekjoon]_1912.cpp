#include <iostream>
#include <vector>

int main()
{
    long total_max = 0;
    int size;

    std::cin >> size;

    std::vector<long> array(size);

    for(int i = 0 ; i < size ; i++)
        std::cin >> array[i];

    /*=======================================*/
    
    total_max = array[0];
    for (int i = 1 ; i < size ; i++)
    {
        array[i] = std::max<long>(array[i], array[i] + array[i - 1]);
        total_max = std::max<long>(array[i], total_max);
    }

    std::cout << total_max << std::endl;
    return 0; 
}

