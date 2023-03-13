/*
	백준 주소 : https://www.acmicpc.net/problem/1463
	난이도 : 실버3
*/

#include <iostream>
#include <vector>

int	make_one(std::vector<int>& memory, int num, int idx)
{
	if (idx < 4)
		return 1;
	//std::cout << "====================================\n";
	std::cout << "idx : " << idx << std::endl;
	if (memory[idx] != 0)
		return memory[idx];
	memory[idx] = make_one(memory, num, idx - 1) + 1;

	if (idx % 3 == 0)
		memory[idx] = std::min(memory[idx], make_one(memory, num, idx / 3) + 1);
	if (idx % 2 == 0)
		memory[idx] = std::min(memory[idx], make_one(memory, num, idx / 2) + 1);
	return memory[idx];
}

int main() 
{
	int num;
	std::cin >> num;
	std::vector<int>	memory(num + 1);

	std::cout << make_one(memory, num, num);
}