#include <iostream>
#include <vector>

std::vector<int>	merge(std::vector<int> &v1, std::vector<int> &v2)
{
	std::vector<int>	res;
	int	i(0);
	int	j(0);
	for (int k(0); k < v1.size() + v2.size(); ++k)
	{
		if (i == v1.size())
		{
			res.push_back(v2[j++]);
			continue ;
		}
		else if (j == v2.size())
		{
			res.push_back(v1[i++]);
			continue ;
		}
		if (v1[i] < v2[j])
			res.push_back(v1[i++]);
		else
			res.push_back(v2[j++]);
	}
	return (res);
}

void	mergeSort(std::vector<int> &v)
{
	if (v.size() < 2)
		return ;
	std::vector<int>	tmp1(v.begin(), v.begin() + v.size() / 2);
	std::vector<int>	tmp2((v.begin() + v.size() / 2), v.end());
	mergeSort(tmp1);
	mergeSort(tmp2);
	v = merge(tmp1, tmp2);
}

void	print_vec(std::vector<int> &val)
{
	for (int i(0); i < val.size(); ++i)
	{
		std::cout << val[i];
		if (i != val.size() - 1)
			std::cout << " ";
	}
}

int main(void)
{
	std::vector<int>	val;
	int	size1, size2;
	std::cin >> size1 >> size2;
	std::cin.clear();
	for (int i(0); i < size1 + size2; ++i)
	{
		int	tmp;
		std::cin >> tmp;
		val.push_back(tmp);
	}
	std::sort(val.begin(), val.end());
	print_vec(val);
}