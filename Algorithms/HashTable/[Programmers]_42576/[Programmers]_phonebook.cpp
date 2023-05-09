/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());   
    sort(completion.begin(), completion.end());
    for (int i = 0; i < participant.size(); i++)
    {
        if (i == participant.size() - 1 || participant[i] != completion[i])
            return participant[i];
    }
}