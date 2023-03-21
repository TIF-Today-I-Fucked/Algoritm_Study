#include <iostream>
#include <vector>

/*
	예시 : 27, 10, 12, 20, 25, 13, 15, 22
*/
void	print_vector(std::vector<int> &v)
{
	for (int i(0); i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

std::vector<int>	merge(std::vector<int> &v1, std::vector<int> &v2)
{
	std::vector<int> res;
	int i(0), j(0);

	for (int k = 0; k < v1.size() + v2.size(); ++k)
	{
		if (i == v1.size())
		{
			res.push_back(v2[j++]);
			continue ;
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
	std::cout << "we think that is v1 : " << std::endl;
	print_vector(v1);
	std::cout << "we think that is v2 : " << std::endl;
	print_vector(v2);
	std::cout << "and Finally res! : " << std::endl;
	print_vector(res);
	std::cout << std::endl;
	return res;
}

void	mergeSort(std::vector<int> &v)
{
	if (v.size() < 2)
		return ;
	// divide
	std::vector<int>	tmp1(v.begin(), v.begin() + v.size() / 2);
	std::vector<int>	tmp2(v.begin() + v.size() / 2, v.end());
	print_vector(v);
	print_vector(tmp1);
	print_vector(tmp2);
	mergeSort(tmp1);
	mergeSort(tmp2);
	// merge
	//std::cout << "==========[merge start]================\n";
	v = merge(tmp1, tmp2);
	//print_vector(v);
	//std::cout << "=====================================\n";

}

int main()
{
	std::vector<int> tmp{27, 10, 12, 20, 25, 13, 15, 22};

	mergeSort(tmp);
	print_vector(tmp);
}