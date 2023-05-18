/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/86491
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    
    vector<int> biggest;
    vector<int> smallest;
    const int size = sizes.size();
    for (int i(0); i < size; ++i)
    {
        if (sizes.at(i).at(0) > sizes.at(i).at(1))
        {
            biggest.push_back(sizes.at(i).at(0));
            smallest.push_back(sizes.at(i).at(1));
        }
        else
        {
            biggest.push_back(sizes.at(i).at(1));
            smallest.push_back(sizes.at(i).at(0));
        }
    }
    const int max_big = *max_element(biggest.begin(), biggest.end());
    const int max_small = *max_element(smallest.begin(), smallest.end());
    answer = max_big * max_small;
    return answer;
}