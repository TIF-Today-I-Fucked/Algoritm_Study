/*
	백준 주소 : https://www.acmicpc.net/problem/1260
	난이도 : 실버2
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adjList[1001];
queue<int>	q;

bool visited_d[1001];
bool visited_b[1001];

void dfs(int start) // 재귀로 구현
{
	visited_d[start] = true;
	cout << start << " ";
	for (int i(0); i < adjList[start].size(); ++i)
	{
		const int next = adjList[start][i];
		if (visited_d[next])
			continue ;
		dfs(next);
	}
}

void bfs(int start) // 재귀로 구현
{
	if (q.empty())
		return ;
	cout << start << " ";
	for (int i(0); i < adjList[start].size(); ++i)
	{
		const int next = adjList[start][i];
		if (!visited_b[next])
		{
			visited_b[next] = true;
			q.push(next);
		}
	}
	q.pop();
	bfs(q.front());
}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) 
	{
        sort(adjList[i].begin(), adjList[i].end());
    }

    dfs(V);
    cout << endl;
	q.push(V);
	visited_b[V] = true;
	bfs(V);

    return 0;
}
