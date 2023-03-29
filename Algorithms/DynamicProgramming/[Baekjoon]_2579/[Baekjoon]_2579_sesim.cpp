#include<iostream>
#include<vector>

int main()
{
	int	num_of_stairs;

	std::cin >> num_of_stairs;
	if (num_of_stairs < 1)
		return (0);
	const int vec_size = num_of_stairs < 3 ? 3 : num_of_stairs;
	
	std::vector<int>	scores(vec_size);
	std::vector<int>	record(vec_size);

	for (int i(0); i < num_of_stairs; ++i)
		std::cin >> scores[i];
	
	record.at(0) = scores.at(0);
	record.at(1) = scores.at(0) + scores.at(1);
	record.at(2) = std::max<int>(scores.at(2) + scores.at(0), scores.at(2) + scores.at(1));
	for (int i(3); i < num_of_stairs; ++i)
	{
		record.at(i) = std::max<int>(record.at(i - 3) + scores.at(i - 1), record.at(i - 2));
		record.at(i) += scores.at(i);
	}
	std::cout << record.at(num_of_stairs - 1);
}