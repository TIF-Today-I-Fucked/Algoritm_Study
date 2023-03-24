#include <iostream>
#include <vector>

int	SumInput(const int& InputNum)
{
	return(((1 + InputNum) * InputNum) / 2);
}

int	FindMaxVal(std::vector<int>& triangle, const int& MaxIdx, const int& InputNum)
{
	int	cur_idx(0);
	int	i(1);
	for (; i < InputNum; ++i)
	{
		cur_idx = SumInput(i);
		for (int k(0); k < i + 1; ++k)
		{
			if (k == 0)
				triangle.at(cur_idx + k) += triangle.at(cur_idx + k - i);
			else if (k == i)
				triangle.at(cur_idx + k) += triangle.at(cur_idx + k - (i + 1));
			else
			{
				int	tmp1 = triangle.at(cur_idx + k) + triangle.at(cur_idx + k - i);
				int	tmp2 = triangle.at(cur_idx + k) + triangle.at(cur_idx + k - (i + 1));
				triangle.at(cur_idx + k) = tmp1 > tmp2 ? tmp1 : tmp2;
			}
		}
	}
	cur_idx = SumInput(i - 1);
	int	res(0);
	for (; cur_idx < MaxIdx; ++cur_idx)
	{
		res = triangle.at(cur_idx) > res ? triangle.at(cur_idx) : res;
	}
	return (res);
}

int	main()
{
	int	InputNum;
	int	MaxIdx;
	std::cin >> InputNum;
	MaxIdx = SumInput(InputNum);

	std::vector<int>	triangle;
	int					tmp;
	for (int i(0); i < MaxIdx; ++i)
	{
		std::cin >> tmp;
		triangle.push_back(tmp);
	}
	std::cout << FindMaxVal(triangle, MaxIdx, InputNum);
}