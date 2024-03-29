/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }
    
    return true;
}