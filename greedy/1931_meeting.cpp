#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef	std::vector<int>	val;

//bool compare(const val& left, const val& right)
//{
//    return left[1] <= right[1];
//}

int main()
{
	int meeting_cnt;
	std::vector<val >	room_hour;
	std::cin >> meeting_cnt;
	if (meeting_cnt < 1)
	{
		std::cout << 0;
		return 0;
	}
	val	tmp(2);
	for (int i(0); i < meeting_cnt; i++)
	{
		std::cin >> tmp[1] >> tmp[0];
		room_hour.push_back(tmp);
	}
	std::vector<val>::iterator	iter_begin = room_hour.begin();
	std::vector<val>::iterator	iter_end = room_hour.end();

	sort(iter_begin, iter_end);
	
	int	i(0);
	int	res(1);
	val tmp_vector = room_hour[i];
	while (++i < meeting_cnt)
	{
		if (room_hour[i][1] < tmp_vector[0])
			continue ;
		tmp_vector = room_hour[i];
		res++;
	}
	std::cout << "====================" << std::endl;
	std::cout << "res : " << res << std::endl;
	std::cout << "====================" << std::endl;


	for (int i(0); i < meeting_cnt; i++)
	{
		std::cout << room_hour.at(i)[0] << " " << room_hour.at(i)[1] << std::endl; 
	}
}