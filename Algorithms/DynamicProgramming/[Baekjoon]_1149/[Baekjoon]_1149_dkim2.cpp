#include <iostream>

int main()
{
	constexpr int R = 0;
	constexpr int G = 1;
	constexpr int B = 2;

	int num;
	std::cin >> num;
	int res[3] {0, 0, 0};
	int cost[3];

	for (int i = 0 ; i < num ; i++)
	{
		std::cin >> cost[R] >> cost[G] >> cost[B];
		cost[R] += (res[B] < res[G]) ? res[B] : res[G];
		cost[G] += (res[R] < res[B]) ? res[R] : res[B];
		cost[B] += (res[G] < res[R]) ? res[G] : res[R];
		res[R] = cost[R];
		res[G] = cost[G];
		res[B] = cost[B];
	}
	int min = (res[R] < res[G])
				?	((res[R] < res[B]) ? res[R] : res[B])
				: 	((res[G] < res[B]) ? res[G] : res[B]);

	std::cout << min << std::endl;
}