#include <iostream>
#include <vector>

long long	orderNum(int n)
{
	std::vector<int>	val;
	std::size_t	i(0);
	for (; i < 10; ++i)
	{
		val.push_back(10 - i);
	}
	int	res(val[0]);
	std:size_t	max(10 * (n - 1));
	for (i = 1; i < max; ++i)
	{
		if (i % 10 == 0)
		{
			val.push_back(res);
			continue ;
		}
		if (i < 10)
		{
			res += val[i];
		}
		else
		{
			long long	sub_val = (val[i - 1] % 10007) - (val[i - 11] % 10007);
			sub_val = sub_val > 0 ? sub_val : sub_val + 10007;
			val.push_back(sub_val % 10007);
			res += sub_val;
		}
	}
	return (res % 10007);
}

int	main()
{
	int	n;
	std::cin >> n;
	std::cout << orderNum(n);
}