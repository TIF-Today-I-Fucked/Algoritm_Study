/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    const int comp_size = completion.size();
    unsigned int i(0);
    for (; i < comp_size; ++i)
    {
        if (participant.at(i) != completion.at(i))
        {
            answer = participant.at(i);
            break ;
        }
    }
    if (i ==  comp_size)
    {
        answer = participant.at(i);
    }
    return answer;
}