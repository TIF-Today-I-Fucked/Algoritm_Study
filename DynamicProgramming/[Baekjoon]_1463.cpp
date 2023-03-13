/*
	백준 주소 : https://www.acmicpc.net/problem/1463
	난이도 : 실버3
*/

#include <iostream>
#include <vector>

int	make_one(std::vector<int>& memory, int num)
{
	int idx(0);
	memory.push_back(0);
	while (++idx <= num)
	{
		if (idx == 1)
		{
			memory.push_back(0);
			continue ;
		}
		memory.push_back(memory[idx - 1] + 1);
		if (idx % 3 == 0)
			memory[idx] = (memory[idx] < memory[idx / 3] + 1 ? memory[idx] : memory[idx / 3] + 1);
		if (idx % 2 == 0)
			memory[idx] = (memory[idx] < memory[idx / 2] + 1 ? memory[idx] : memory[idx / 2] + 1);
	}
	return memory[num];
}

int main()
{
	int num;
	std::cin >> num;
	std::vector<int>	memory;

	std::cout << make_one(memory, num);
}