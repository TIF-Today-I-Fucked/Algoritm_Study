#include <iostream>
#include <array>
#include <vector>

enum Color
{
    R, G, B
};
enum Color GetNextCostIndex(int curr_index, int level, const std::vector<int[3]> &costs);

int main()
{
    int level;
    std::cin >> level;

    std::vector<int[3]> all_costs(level);
    for (int i = 0 ; i < level ; i++)
        std::cin >> all_costs[i][R] >> all_costs[i][G] >> all_costs[i][B];

    std::cout << "======================================\n";
    unsigned long cost_sum[3] { (unsigned long)all_costs[0][R], 
                                (unsigned long)all_costs[0][G], 
                                (unsigned long)all_costs[0][B] };
    {
        std::cout << cost_sum[R] << " " << cost_sum[G] << " " << cost_sum[B] << std::endl;
    }
                            
    for (int i = 1 ; i < level ; i++)
    {
        unsigned long temp[3];
        temp[R] = std::min<unsigned long>(cost_sum[G], cost_sum[B]);
        temp[G] = std::min<unsigned long>(cost_sum[R], cost_sum[B]);
        temp[B] = std::min<unsigned long>(cost_sum[G], cost_sum[R]);

        cost_sum[R] += (temp[R] += all_costs[i][R]);
        cost_sum[G] += (temp[G] += all_costs[i][G]);
        cost_sum[B] += (temp[B] += all_costs[i][B]);
        
        {
            std::cout << cost_sum[R] << " " << cost_sum[G] << " " << cost_sum[B] << std::endl;
        }
    }   
}

// enum Color GetNextCostIndex(int i, int l, const std::vector<int[3]> &costs)
// {

// }
