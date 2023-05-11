/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42578
*/

#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer(1);
    map<string, int> wear;
    int c_size = clothes.size();
    
    for (int i = 0; i < c_size; i++)
    {
        if (wear.find(clothes[i][1]) != wear.end())
            wear[clothes[i][1]]++;
        else
            wear[clothes[i][1]] = 1;
    }
    for (auto it = wear.begin(); it != wear.end(); it++)
    {
        answer *= ((it->second) + 1);
    }
    return answer - 1;
}