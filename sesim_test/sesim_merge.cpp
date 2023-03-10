#include <climits>
#include <iostream>
#include <vector>

typedef std::vector<int>	vec;

vec	merge(const vec& tmp1, const vec& tmp2)
{
	vec	res;
	std::size_t	i(0);
	std::size_t	j(0);
	for (std::size_t k(0); k < tmp1.size() + tmp2.size(); ++k)
	{
		if (i == tmp1.size())
		{
			res.push_back(tmp2[j++]);
			continue;
		}
		else if (j == tmp2.size())
		{
			res.push_back(tmp1[i++]);
			continue;
		}
		if (tmp1[i] < tmp2[j])
			res.push_back(tmp1[i++]);
		else
			res.push_back(tmp2[j++]);
	}
	return res;
}

void	mergeSort(vec& val)
{
	if (val.size() < 2)
		return ;
	vec	tmp1(val.begin(), val.begin() + (val.size() / 2));
	vec	tmp2(val.begin() + (val.size() / 2), val.end());
	mergeSort(tmp1);
	mergeSort(tmp2);
	val = merge(tmp1, tmp2);
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
	mergeSort(tmp);
	print_vec(tmp);
}