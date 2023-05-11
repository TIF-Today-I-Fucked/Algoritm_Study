/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer(true);
    
    const int book_size = phone_book.size();
    sort(phone_book.begin(), phone_book.end());
    
    for (unsigned int i(0); i < book_size - 1; ++i)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return (false);
    }
    
    return answer;
}