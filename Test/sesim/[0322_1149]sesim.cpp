#include <iostream>
#include <vector>
#include <cstring>

int	main()
{
	int	n;
	std::cin >> n;
	int	tmp[3 * n];
	bzero(&tmp, sizeof(tmp));
	int i(0);
	for (; i < (n * 3); i+=3)
	{
		switch (i)
		{
			case 0:
				std::cin >> tmp[0] >> tmp[1] >> tmp[2];
				break;
			default:
				std::cin >> tmp[i] >> tmp[i + 1] >> tmp[i + 2];
				tmp[i] += std::min<int>(tmp[i - 2], tmp[i - 1]);
				tmp[i + 1] += std::min<int>(tmp[i - 3], tmp[i - 1]);
				tmp[i + 2] += std::min<int>(tmp[i - 3], tmp[i - 2]);
		}
	}
	std::cout << std::min<int>(std::min<int>(tmp[i - 3], tmp[i - 2]), tmp[i - 1]);
}