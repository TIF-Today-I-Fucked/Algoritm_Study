/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    const int size = commands.size();
    cout << size << endl;
    for (int i(0); i < size; ++i)
    {
        vector<int> tmp((array.begin() + commands.at(i).at(0) - 1), (array.begin() + commands.at(i).at(1)));
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp.at(commands.at(i).at(2) - 1));
    }
    return answer;
}