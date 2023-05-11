/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42579
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second < b.second;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, \
        pair<int, \
            priority_queue<pair<int, int>, \
                    vector<pair<int, int>>, \
                    cmp>\
            >\
        > \
        val;
    
    const int total_size = genres.size();
    for (int i(0); i < total_size; ++i)
    {
        val[genres.at(i)].first += plays.at(i);
        
        val[genres.at(i)].second.push({i, plays.at(i)});
    }
    while (!val.empty())
    {
        auto pr = \
            std::max_element(val.begin(), val.end(), \
                             [](const auto &x, const auto &y)
                {
                    return x.second.first < y.second.first;
                });
        
        answer.push_back(pr->second.second.top().first);
        pr->second.second.pop();
        if (!pr->second.second.empty())
        {
            answer.push_back(pr->second.second.top().first);
            pr->second.second.pop();
        }
        val.erase(pr->first);
    }
    
    return answer;
}