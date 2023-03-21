#include <climits>
#include <iostream>
#include <vector>

typedef std::vector<int>	vec;

void	quickSort(vec& val, int left, int right)
{
	if (left >= right)
		return ;
	int mov_left(left);
	int mov_right(right);
	int	mid = (left + right) / 2;
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

void	print_vec(const vec& val)
{
	for (vec::const_iterator it = val.begin(); it != val.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main()
{
	vec tmp = {27, 10, 12, 20, 25, 13, 15, 22};
	quickSort(tmp, 0, tmp.size() - 1);
	print_vec(tmp);
}