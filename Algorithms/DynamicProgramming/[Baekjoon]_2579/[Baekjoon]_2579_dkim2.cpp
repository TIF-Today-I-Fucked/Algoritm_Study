#include<iostream>
#include<vector>

int main()
{
	int NumOfStairs;

	std::cin >> NumOfStairs;

	std::vector<int> StairScores(NumOfStairs);

	for (auto it = StairScores.end() - 1 ; it >= StairScores.begin() ; --it)
		std::cin >> *it;

	if (NumOfStairs == 1)
		return StairScores[0];
	else if (NumOfStairs == 2)
		return StairScores[0] + StairScores[1];
	else if (NumOfStairs == 3)
		return StairScores[0] + std::max<int>(StairScores[1] , StairScores[2]);
	std::vector<int> MaxScores(NumOfStairs);
	MaxScores[0] = StairScores[0];
	MaxScores[1] = StairScores[0] + StairScores[1];
	MaxScores[2] = StairScores[0] + std::max<int>(StairScores[1] , StairScores[2]);
	std::cout << MaxScores[0] << " ";
	std::cout << MaxScores[1] << " ";
	for (int i = 3; i < NumOfStairs ; i++)
	{
		MaxScores[i] = MaxScores[i - 3] + StairScores[i - 1] + StairScores[i];
		if (MaxScores[i] < MaxScores[i - 2] + StairScores[i])
		{
			MaxScores[i] = MaxScores[i - 2] + StairScores[i];
		}
		std::cout << MaxScores[i] << " ";
	}
	std::cout << std::endl;
	std::cout << *(MaxScores.end() - 1); 	
}