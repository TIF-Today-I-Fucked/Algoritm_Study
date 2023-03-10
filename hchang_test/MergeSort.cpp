#include <iostream>
#include <vector>

void	print_vec(std::vector<int> &v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::vector<int>	merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> res;
	int i(0), j(0);

	for (int k = 0; k < a.size() + b.size(); k++)
	{
		if (i == a.size())
		{
			res.push_back(b[j++]);
			continue;
		}
		else if (j == b.size())
		{
			res.push_back(a[i++]);
			continue;
		}
		if (a[i] < b[j])
			res.push_back(a[i++]);
		else
			res.push_back(b[j++]);
	}
	
	return res;
}

void	mergeSort(std::vector<int> &v)
{
	if (v.size() < 2)
		return ;

	std::vector<int> res;

	std::vector <int> tmp1(v.begin(), v.begin() + v.size() / 2);
	std::vector <int> tmp2(v.begin() + v.size() / 2, v.end());

	mergeSort(tmp1);
	mergeSort(tmp2);

	v = merge(tmp1, tmp2);
}

int main()
{
	std::vector<int> tmp{27, 10, 12, 20, 25, 13, 15, 22};

	mergeSort(tmp);
	print_vec(tmp);
}