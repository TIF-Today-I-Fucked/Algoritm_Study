/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42579
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b) const { return a.second < b.second; }
};

bool    cmp2(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // first idx / second plays
    
    map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>>    map_vec;
    map<string, int>                                                            map_total;
    for (int i = 0; i < genres.size(); i++)
    {
        map_vec[genres[i]].push(make_pair(i, plays[i]));
        map_total[genres[i]] += plays[i];
    }
    vector<pair<string, int>>                  vec_total(map_total.begin(), map_total.end());
    sort(vec_total.begin(), vec_total.end(), cmp2);
    
    // vec_total : answer 순서 
    // map_vec   : plays의 순서
    
    for (int i = 0; i < vec_total.size(); i++)
    {
        int idx = 0;
        string name = vec_total[i].first;
        while(idx < 2 && !map_vec[name].empty())
        {
            int tmp = map_vec[name].top().first;
            map_vec[name].pop();
            answer.push_back(tmp);
            idx++;
        }
    }
    return answer;
}