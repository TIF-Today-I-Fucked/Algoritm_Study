#include <iostream>
#include <vector>

int main()
{
    int Levels;

    std::cin >> Levels;
    int TotalNumbers = Levels * (Levels + 1) / 2;
    std::vector<int> NumberTriangle(TotalNumbers);

    for(auto it = NumberTriangle.begin(); it < NumberTriangle.end() ; it++)
        std::cin >> *it;
    
    for (int l = Levels ; l > 0 ; l--)
    {
        int Index1 = TotalNumbers - l;
        int Index2 = Index1 - (l - 1);

        for (int i = 0 ; i < (l - 1) ; i++)
            NumberTriangle[Index2 + i] += std::max<int>(NumberTriangle[Index1 + i], NumberTriangle[Index1 + i + 1]);
        TotalNumbers = Index1;
    }

    std::cout << NumberTriangle[0] << std::endl;
}