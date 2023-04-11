#include <iostream>
#include <vector>


int	main()
{
	int	n;
	std::cin >> n;

	int	N;
	int	R;
	int	res;
	int	tmp;
	for (int i(0); i < n; ++i)
	{
		tmp = 1;
		res = 1;
		std::cin >> R >> N;
		for (int j(N); j > N - R; --j)
		{
			res *= j;
			res /= tmp++;
		}
		std::cout << res << std::endl;
	}
}