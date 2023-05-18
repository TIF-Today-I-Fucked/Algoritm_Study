/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42748
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    const int size = citations.size();
    for (unsigned int i(0); i < size; ++i)
    {
        if (citations.at(i) >= size - i)
            answer += 1;
    }
    return answer;
}