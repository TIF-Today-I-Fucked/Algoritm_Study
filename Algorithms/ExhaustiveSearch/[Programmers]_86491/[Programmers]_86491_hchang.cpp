/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/86491
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int w(0);
    int h(0);
    for (int i = 0; i < sizes.size(); i++)
    {
        int first = sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1];
        int second = sizes[i][0] < sizes[i][1] ? sizes[i][0] : sizes[i][1];
        
        w = first > w ? first : w;
        h = second > h ? second : h;
    }
    return (w * h);
}