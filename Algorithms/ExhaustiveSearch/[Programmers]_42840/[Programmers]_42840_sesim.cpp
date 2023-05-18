/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42840
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    const int total_size = answers.size();
    const int first_size = first.size();
    const int second_size = second.size();
    const int third_size = third.size();
    
    int tmp[3] = {0, };
    
    for (int i(0); i < total_size; ++i)
    {
        if (answers.at(i) == first.at(i % first_size))
            tmp[0]++;
        if (answers.at(i) == second.at(i % second_size))
            tmp[1]++;
        if (answers.at(i) == third.at(i % third_size))
            tmp[2]++;
    }
    
    vector<int> answer;
    
    const int max = *max_element(tmp, tmp + 3);
    for (int i(0); i < 3; ++i)
    {
        if (tmp[i] == max)
            answer.push_back(i + 1);
    }
    return answer;
}