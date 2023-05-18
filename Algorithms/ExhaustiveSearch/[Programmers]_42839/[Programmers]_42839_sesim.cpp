/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42839
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i(2); i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return (false);
    }
    return (true);
}

int solution(string numbers) {
    int answer = 0;
    vector<int> nums;
    vector<char> num_set;
    
    const int length = numbers.length();
    
    for (int i(0); i < length; ++i)
    {
        num_set.push_back(numbers.at(i));
    }
    sort(num_set.begin(), num_set.end());
    
    do
    {
        string tmp = "";
        for (int i(0); i < num_set.size(); ++i)
        {
            tmp.push_back(num_set.at(i));
            nums.push_back(stoi(tmp));
        }
    }
    while (next_permutation(num_set.begin(), num_set.end()));
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for (int i(0); i < nums.size(); ++i)
    {
        if (isPrime(nums.at(i)))
            answer++;
    }
    
    return answer;
    
}