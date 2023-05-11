/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42578
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    const int clothes_size = clothes.size();
    map<string, int> val;
    
    for (unsigned int i(0); i < clothes_size; ++i)
    {
        const auto it = val.find(clothes.at(i).at(1));
        if (it != val.end())
            it->second += 1;
        else
            val.insert(pair<string, int>(clothes.at(i).at(1), 1));
    }
    for (auto it = val.begin(); it != val.end(); ++it)
    {
        answer *= it->second + 1;
    }
    return (answer - 1);
}