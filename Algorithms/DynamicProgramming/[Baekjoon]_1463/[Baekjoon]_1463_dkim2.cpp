#include <iostream>
#include <vector>

int function(int);

int main()
{
	int number; // 1 < number <= 10^6
	std::cin >> number;
	std::cout << function(number) << std::endl;
}

int function(int n)
{
	std::vector<int> cost(n+1);

	int i = 2;
	for ( ; i <= n ; i++)
	{
		cost[i] = cost[i - 1] + 1;
		if (i % 3 == 0)
		{
			cost[i] = std::min<int>(cost[i / 3] + 1, cost[i]);
		}
		if (i % 2 == 0)
		{
			cost[i] = std::min<int>(cost[i / 2] + 1, cost[i]);
		}
	}
	return cost[i - 1];
}