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

void	quickSort(std::vector<int> &v, int left, int right)
{
	if (left >= right)
		return ;
	int pivot = v[(left + right) / 2];
	int m_left(left), m_right(right);
	
	while (left <= right)
	{
		while (v[left] < pivot)
			left++;
		while (pivot < v[right])
			right--;
		if (left <= right)
			std::swap(v[left++], v[right--]);
	}
	quickSort(v, left, m_right);
	quickSort(v, m_left, right);
}

int main()
{
	int n;
	std::vector<int> v;
	
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
	}
	quickSort(v, 0, v.size() - 1);
	print_vec(v);
}
