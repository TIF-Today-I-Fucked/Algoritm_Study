#include <iostream>
#include <array>
#include <vector>

using ulong_t = unsigned long;

int main()
{
	int Digits; // 1 <= Digits <= 100;
	std::cin >> Digits;
	std::vector<std::array<ulong_t, 11>> AllCost(Digits + 1);
	
	AllCost[1].fill(1);
	AllCost[1].back() = 0;
	
	for (int i = 2 ; i <= Digits ; i++)
	{
		const std::array<ulong_t, 11>&	LastLine = AllCost[i-1];
		std::array<ulong_t, 11>&		CurrLine = AllCost[i];
		CurrLine[0] = LastLine[1];
		for (int j = 1 ; j <= 9 ; j++)
			CurrLine[j] = (LastLine[j-1] + LastLine[j+1]) % 1000000000;
	}
	unsigned long res = 0;
	const std::array<ulong_t, 11>&	FinalLine = AllCost[Digits];
	for (int i = 1 ; i <= 9 ; i++)
		res = (res + FinalLine[i]) % 1000000000;
	std::cout << res << std::endl;
	return 0;
}
