/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/1845
*/

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    std::map<int, int>  various;
    
    const int vec_size = nums.size();
    for (unsigned int i = 0; i < vec_size; ++i)
    {
        various.insert(pair<int, int>(nums[i], 1));
    }
    const int take_nums = vec_size / 2;
    const int map_size = various.size();
    answer = take_nums < map_size ? take_nums : map_size;
    return answer;
}