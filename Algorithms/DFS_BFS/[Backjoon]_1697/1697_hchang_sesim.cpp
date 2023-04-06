/*
	백준 주소 : https://www.acmicpc.net/problem/1697
	난이도 : 실버1
	문제 이름 : 숨바꼭질
*/

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
const int	MAX = 100001; // 최대 위치
bool		visited[MAX];

int	bfs(const int& x, const int& y)
{
	int cnt(-1);
	int	size(0);
	
	queue<int>	q;
	q.push(x);
	while(!q.empty())
	{
		size = q.size();
		cnt++;
		while (size--)
		{
			const int	front = q.front();
			//std::cout << front << std::endl;
			if (front == y)
				return cnt;
			if (2 * front < MAX && visited[2 * front] == false )
			{
				q.push(2 * front);
				visited[2 * front] = true;
			}
			if (front + 1 < MAX && visited[front + 1] == false)
			{
				q.push(front + 1);
				visited[front + 1] = true;

			}
			if (front - 1 >= 0 && visited[front - 1] == false)
			{
				q.push(front - 1);
				visited[front - 1] = true;
			}
			q.pop();
		}
	}
	return (0);
}

int main()
{
	int x, y;
	cin >> x >> y;
	
	cout << bfs(x, y);
}