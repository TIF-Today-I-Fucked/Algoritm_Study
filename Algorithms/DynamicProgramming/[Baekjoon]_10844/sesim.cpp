#include <iostream>
#include <vector>

int	easyStairNum(const int& input)
{
	if (input < 2)
		return (9);
	std::vector<unsigned long>	mem;
	
	int	i(0);
	unsigned long	res(0);
	for (; i < 10; ++i)
	{
		mem.push_back(1);
	}
	for (; i < (input * 10); ++i)
	{
		if (i % 10 == 0)
		{
			mem.push_back(mem[i - 9] % 1000000000);
		}
		else if (i % 10 == 9)
		{
			mem.push_back(mem[i - 11] % 1000000000);
			if (i >= (input - 1) * 10)
				res = (res + mem[i]) % 1000000000;
		}
		else
		{
			mem.push_back((mem[i - 11] + mem[i - 9]) % 1000000000);
			if (i >= (input - 1) * 10)
				res = (res + mem[i]) % 1000000000;
		}
	}
	return (res);
}

int	main()
{
	int	input;
	std::cin >> input;
	std::cout << easyStairNum(input);
}