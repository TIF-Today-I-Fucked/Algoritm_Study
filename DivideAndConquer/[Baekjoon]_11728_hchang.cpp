#include <iostream>
#include <vector>

void	print_vec(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		if (it != vec.end())
			std::cout << " ";
	}
}

std::vector<int>	merge(std::vector<int> &v1, std::vector<int> &v2)
{
	int i(0), j(0);
	std::vector<int> res;

	for (int k = 0; k < v1.size() + v2.size(); k++)
	{
		if (i == v1.size())
		{
			res.push_back(v2[j++]);
			continue;
		}
		else if (j == v2.size())
		{
			res.push_back(v1[i++]);
			continue;
		}
		if (v1[i] < v2[j])
			res.push_back(v1[i++]);
		else
			res.push_back(v2[j++]);
	}
	return res;
}

void	mergeSort(std::vector<int> &v)
{
	if (v.size() < 2)
		return ;
	std::vector<int> tmp1(v.begin(), v.begin() + (v.size() / 2));
	std::vector<int> tmp2(v.begin() + (v.size() / 2), v.end());
	mergeSort(tmp1);
	mergeSort(tmp2);

	v = merge(tmp1, tmp2);
}

int main()
{
	int n, m, total;
	std::vector<int> v;

	std::cin >> n >> m;
	total = n + m;
	for (int i = 0; i < total; i++)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
	}
	mergeSort(v);
	print_vec(v);
}
