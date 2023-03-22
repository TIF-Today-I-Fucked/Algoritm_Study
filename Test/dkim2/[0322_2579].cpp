#include<iostream>

using unsigned long u_long;
int main()
{
    unsigned int num_of_stairs;

    std::cin >> num_of_stairs;
    std::vector<int> scores(num_of_stairs + 4);
    for (int i = 1 ; i <= num_of_stairs ; i++)
        std::cin >> scores[num_of_stairs - i];

    u_long cost_comp[2] {0, 0};
    u_long cost = 0;
    int i = 0;
    while( i < num_of_stairs)
    {
        int next_i1, next_i2;
        cost_comp[0] = scores[i + 2];
        cont_comp[1] = scores[i + 1] + scores[i + 3];

        if
    }
    
}