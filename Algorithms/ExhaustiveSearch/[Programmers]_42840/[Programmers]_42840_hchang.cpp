/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42840
*/

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p1 = {1, 2, 3, 4, 5};
vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int size[3];
    size[0] = p1.size();
    size[1] = p2.size();
    size[2] = p3.size();
    
    int score[3] = {0, };
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == p1[i % size[0]]) score[0]++;
        if (answers[i] == p2[i % size[1]]) score[1]++;
        if (answers[i] == p3[i % size[2]]) score[2]++;
    }

    int max = *max_element(score, score + 3);
    for (int i = 0; i < 3; i++)
    {
        if (max == score[i])
            answer.push_back(i + 1);
    }
    return answer;
}