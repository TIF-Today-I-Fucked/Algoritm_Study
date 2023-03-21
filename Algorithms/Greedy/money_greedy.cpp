#include <iostream>
#include <vector>
#include <map>

std::vector<int> money = {10, 50, 100, 500};
std::map<int, int> res_val = {{500, 0}, {100, 0}, {50, 0}, {10, 0}};

// 첫번째 인자값 -> 얼마 안들면 되는 지 
int main(int argc, char **argv)
{
	int idx = money.size() - 1;
	std::map<int, int>::iterator	it = res_val.find(500);
	
	if (argc != 2)
		exit (0);
	int	cur_money = atoi(argv[1]);
	if (cur_money % 10 != 0)
		exit (0);
	while (cur_money > 0)
	{
		if ((cur_money - money[idx]) < 0)
		{
			idx--;
			it = res_val.find(money[idx]);
			continue ;
		}
		cur_money -= money[idx];
		(it->second)++;
	}
	for(std::map<int, int>::iterator iter = res_val.begin(); iter != res_val.end(); iter++)
	{
		std::cout << iter->first << "원 : " << iter->second << "개 사용" << std::endl;
	}
	return 1;
}
