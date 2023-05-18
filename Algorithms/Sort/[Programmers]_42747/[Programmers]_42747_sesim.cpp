/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

bool cmp(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    
    vector<string>  vals;
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        vals.push_back(to_string(*it));
    }
    sort(vals.begin(), vals.end(), cmp);
    for (auto it = vals.begin(); it != vals.end(); ++it)
    {
        answer += *it;
    }
    unsigned int i(0);
    for (; i < answer.size(); ++i)
    {
        if (answer.at(i) != '0')
            break;
    }
    if (i == answer.size())
        return "0";
    return answer;
}