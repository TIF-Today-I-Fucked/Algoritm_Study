#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    std::vector<int> tests{1074, 1629, 1780};
    int a = rand() % tests.size();
    int b = rand() % tests.size();

    if (a == b)
    {
        a = rand() % tests.size();
        b = rand() % tests.size();   
    }

    std::cout << " 🔥 오늘의 문제는 ?!" << std::endl;
    std::cout << "     첫번째 문제 -> " << tests[a] << " 입니다!" <<std::endl;
    std::cout << "     두번째 문제 -> " << tests[b] << " 입니다!" <<std::endl;

}