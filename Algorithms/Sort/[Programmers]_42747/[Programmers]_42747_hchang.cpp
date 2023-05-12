/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool    cmp(int a, int b)
{
    string str_a = to_string(a);
    string str_b = to_string(b);
    
    string tmp_a = str_a + str_b;
    string tmp_b = str_b + str_a;
    
    int num_a = stoi(tmp_a);
    int num_b = stoi(tmp_b);

    return num_a > num_b;
}


string solution(vector<int> numbers) {
    string answer = "";
    int tmp = 0;
    sort(numbers.begin(), numbers.end(), cmp);
    for (int i = 0 ; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
        tmp += numbers[i];
    }
    if (tmp == 0)
        return "0";
    return answer;
}
