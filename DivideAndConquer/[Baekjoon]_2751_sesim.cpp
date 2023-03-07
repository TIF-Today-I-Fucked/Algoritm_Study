#include <iostream>
#include <vector>

void	quickSort(std::vector<int>& val, int left, int right)
{
	if (left >= right)
		return;
	int	mid = (left + right) / 2;
	int	mov_left(left);
	int	mov_right(right);
	while (mov_left <= mov_right)
	{
		while (val[mov_left] < val[mid])
			mov_left++;
		while (val[mov_right] > val[mid])
			mov_right--;
		if (mov_left <= mov_right)
			std::swap(val[mov_left++], val[mov_right--]);
	}
	quickSort(val, left, mov_right);
	quickSort(val, mov_left, right);
}

void	print_vector(std::vector<int>& val)
{
	for (int i(0); i < val.size(); ++i)
	{
		std::cout << val[i];
		if (i != val.size() - 1)
			std::cout << "\n";
	}
}

int	main(void)
{
	std::vector<int>	val;
	int	size;
	std::cin >> size;
	std::cin.clear();
	int	tmp;
	for (int i(0); i < size; ++i)
	{
		std::cin >> tmp;
		val.push_back(tmp);
		std::cin.clear();
	}
	quickSort(val, 0, val.size() - 1);
	print_vector(val);
}
