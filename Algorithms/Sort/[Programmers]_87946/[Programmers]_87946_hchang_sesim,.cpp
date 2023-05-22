/*
	프로그래머스 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/87946
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

//k	    dungeons	                result
//80	[[80,20],[50,40],[30,10]]	3

bool	visited[8];
int		answer = -1;

void    dfs(const vector<vector<int>>& dungeons, int cur_max, int cnt)
{
	if (cur_max <= 0)
		return ;
	for (int i(0); i < dungeons.size(); ++i)
	{
		if (dungeons[i][0] <= cur_max && !visited[i])
		{
			visited[i] = true;
			dfs(dungeons, cur_max - dungeons[i][1], cnt + 1);
			visited[i] = false;
		}
	}
	answer = max<int>(answer, cnt);

}

int solution(int cur_max, vector<vector<int>> dungeons)
{
	dfs(dungeons, cur_max, 0);
    return answer;
}