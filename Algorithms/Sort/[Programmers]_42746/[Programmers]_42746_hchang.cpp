/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer(0);
    int size = citations.size();
    
    sort(citations.begin(), citations.end(), greater<>());
    if (citations[0] == 0)
        return 0;
    for (int i = 0; i < size; i++)
    {
        if (citations[i] > i)
            answer++;
        else
            break;
    }
    return answer;
}

// 0 1 3 5 6 
// 6 5 3 1 0

// 1 1 2
// 2 1 1 

// 2 2 2
// 4 4 4

// 25 8 5