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

std::vector<int>	merge(std::vector<int> &v1, std::vector<int>& v2)
{
	std::vector<int>	res;
	int	i(0);
	int	j(0);
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
		if(v1[i] < v2[j])
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
	std::vector<int> tmp2((v.begin() + v.size() / 2), v.end());
	mergeSort(tmp1);
	mergeSort(tmp2);
	v = merge(tmp1, tmp2);
}

int main()
{
	int n;
	std::vector<int> v;
	
	std::cin >> n;
	std::cin.clear();
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
		std::cin.clear();
	}
	mergeSort(v);
	print_vec(v);
}
