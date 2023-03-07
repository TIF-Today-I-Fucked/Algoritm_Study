/*
프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42860
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

bool	direction(std::string &name)
{
	int idx(0);
	int mid_point(name.size() / 2);

	while (name[1 + idx] == 'A' && name[name.size() - 1 - idx] == 'A' && idx <= mid_point)
		idx++;
	if (name[1 + idx] == 'A')
		return true; // 역방향
	else
		return false; // 정방향
}

// check point
// int	multiple_a_edge_case(std::string& name)
// {
// 	int	i;
// 	int	k;
// 	i = name.size() / 2;
// 	k = name.size() / 2 + 1;
// 	while (name[i] == 'A')
// 		--i;
// 	while (name[k] == 'A')
// 		++k;
// 	int	a_size = k - i;
// 	int	rest_size = name.size() - a_size;
// 	if (a_size >= rest_size)
		
// }

int solution(std::string name)
{
    int answer = 0;
	
	if (direction(name))
	{
		std::string substr = name.substr(1, name.size() - 1);
		reverse(substr.begin(), substr.end());
		name.erase(name.begin() + 1, name.end());
		name += substr;
	}
	// std::cout << name << std::endl;

	int idx(name.size() - 1);
	while(name[idx] == 'A')
		name.erase(idx--);
	std::cout << name << std::endl;
   for (int i(0); i < name.size(); ++i)
   {
		if (name[i] == 'A')
		{
			answer++;
			continue ;
		}
		answer += std::min(-('A' - name[i]), ('Z' - name[i] + 1));
		std::cout << "biach~ " <<  std::min(-('A' - name[i]), ('Z' - name[i])) << std::endl;
		if (i == (name.size() - 1))
			continue ;
		answer++;
   } 
    
    
    return answer;
}

int main()
{
	std::cout << solution("AAAAACAACAAAAA") << std::endl;

}