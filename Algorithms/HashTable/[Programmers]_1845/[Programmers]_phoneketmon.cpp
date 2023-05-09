/*
프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/1845
*/

#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int nums_size = nums.size() / 2;
    map<int, int>   nums_map;
    
    for (int i = 0; i < nums.size(); i++)
    {
        nums_map.insert({nums[i], 1});
    }
    int map_size = nums_map.size();
    
        
        
    return nums_size > map_size ? map_size : nums_size;
}