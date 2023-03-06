/*
프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42862
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int solution(int n, std::vector<int> &lost, std::vector<int> &reserve) {
	int	res(n - lost.size());
    
    // sort(lost.begin(), lost.end());
    // sort(reserve.begin(), reserve.end());
    

    for (int i(0); i < lost.size(); ++i)    
	{
        for (int k(0); k < reserve.size(); ++k)    
        {
            if (lost[i] == reserve[k])
            {
                res++;
                reserve[k] = -2147483648;
                lost[i] = -2147483648;
                break ;
            }
        }
    }
    
	for (int i(0); i < lost.size(); ++i)
	{
        if (lost[i] == -2147483648)
            continue;
		for (int k(0); k < reserve.size(); ++k)
		{
			if ((lost[i] == (reserve[k] - 1)) || (lost[i] == (reserve[k] + 1)))
			{
				res++;
				reserve[k] = -2147483648;
                break ;
			}
		}
	}
	return (res);
}

int	main()
{
	std::vector<int>	lost{ 4, 2 };
	std::vector<int>	reserve{ 3, 5 };
	
	std::cout << solution(5, lost, reserve) << std::endl;
	
	for (int i(0); i < lost.size(); ++i)
	{
		std::cout << lost[i] << " ";
	}
	std::cout << std::endl;
	for (int k(0); k < reserve.size(); ++k)
	{
		std::cout << reserve[k] << " ";
	}
	std::cout << std::endl;
}
