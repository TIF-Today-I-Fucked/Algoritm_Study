/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/84512
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> mapp = 
{
    {'A', 0},
    {'E', 1},
    {'I', 2},
    {'O', 3},
    {'U', 4}
};

int solution(string word) {
    int answer = 0;
    
    for (int i = 0; i < word.size(); ++i)
    {
        if (i == 0)
        {
            answer += (mapp[word[i]] * 780) + (mapp[word[i]] + 1);
        }
        else if (i == 1)
        {
            answer += (mapp[word[i]] * 155) + (mapp[word[i]] + 1);
        }
        else if (i == 2)
        {
            answer += (mapp[word[i]] * 30) + (mapp[word[i]] + 1);
        }
        else if (i == 3)
        {
            answer += (mapp[word[i]] * 5) + (mapp[word[i]] + 1);
        }
        else
        {
            answer += (mapp[word[i]] + 1);
        }
    }
    return answer;
}