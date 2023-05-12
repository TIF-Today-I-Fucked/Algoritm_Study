/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42748
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> tmp(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}