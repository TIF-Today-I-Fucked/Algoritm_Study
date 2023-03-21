#include <iostream>
#include <vector>

/*
	예시 : 27, 10, 12, 20, 25, 13, 15, 22
*/

void	print_vec(std::vector<int> v)
{
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it;
		if (it != v.end() - 1)
			std::cout << "\n";
	}
}

//void	print_vector(std::vector<int> &v)
//{
//	for (int i(0); i < v.size(); ++i)
//		std::cout << v[i] << " ";
//	std::cout << std::endl;
//}

//void	print_part_vector(std::vector<int> &v, int begin, int end)
//{
//	std::cout << "[ ";
//	for (int i(begin); i <= end; ++i)
//		std::cout << v[i] << " ";
//	std::cout << "]" << std::endl;
//}

void	quickSort(std::vector<int> &v, int left, int right)
{
	//std::cout << "===================================\n";
	//std::cout << "my left : " << left << " | my right : " << right << std::endl;
	//print_part_vector(v, left, right);
	//std::cout << "===================================\n";
	if (left >= right)
		return ;
	int mid = (right + left) / 2;
	int	mov_left(left);
	int	mov_right(right);
	while (mov_left <= mov_right)
	{
		while (v[mov_left] < v[mid])
			mov_left++;
		while (v[mov_right] > v[mid])
			mov_right--;
		if (mov_left <= mov_right)
			std::swap(v[mov_left++], v[mov_right--]);
	}
	quickSort(v, left, mov_right);
	quickSort(v, mov_left, right);
}

//int main()
//{
//	std::vector<int> tmp{27, 10, 12, 20, 25, 13, 15, 22};
//	quickSort(tmp, 0, tmp.size() - 1);
//	print_vector(tmp);
//}
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
	print_vec(val);
}
