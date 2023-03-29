/*
	백준 주소 : https://www.acmicpc.net/problem/1912
	난이도 : 실버2
*/

#include <iostream>
#include <vector>

int	main()
{
	int	input;
	std::cin >> input;

	std::vector<long>	val(input);
	long				max;
	for (int i(0); i < input; ++i)
	{
		std::cin >> val[i];
		if (i == 0)
		{
			max = val[0];
			continue ;
		}
		val[i] = std::max<long>(val[i], val[i] + val[i - 1]);
		max = std::max<long>(max, val[i]);
	}
	std::cout << max;
}