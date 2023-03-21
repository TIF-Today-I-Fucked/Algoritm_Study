#include <iostream>
#include <vector>

void	print_vec(std::vector<int> &v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	QuickSort(std::vector<int> &tmp, int left, int right)
{
	if (left > right)
		return ;
	int mid = (right + left) / 2;
	int mov_left(left), mov_right(right);

	while (mov_left <= mov_right)
	{
		while (tmp[mov_left] < tmp[mid])
			mov_left++;
		while (tmp[mov_right] > tmp[mid])
			mov_right--;
		if (mov_left <= mov_right)
			std::swap(tmp[mov_left++], tmp[mov_right--]);
	}
	
	QuickSort(tmp, left, mov_right);
	QuickSort(tmp, mov_left, right);
}


int main()
{
	std::vector<int> tmp{27, 10, 12, 20, 25, 13, 15, 22};

	QuickSort(tmp, 0, tmp.size() - 1);
	print_vec(tmp);
	
}