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
bool visited1[1001];
bool visited2[1001];

void bfs(int start)
{
	queue<int>	q;
	q.push(start);

	while (!q.empty())
	{
		const int cur = q.front();
		q.pop();
		if (visited1[cur])
		{
			continue;
		}
		visited1[cur] = true;
        cout << cur << " ";
		for (int i = 0; i < adjList[cur].size(); i++)
		{
			const int	next = adjList[cur][i];
			if (!visited1[next])
			{
				q.push(next);
			}
		}
	}
}

void dfs(int start)
{
	stack<int> s;
	s.push(start);

	while (!s.empty())
	{
		const int curr = s.top();
        s.pop();
        if (visited2[curr])
            continue;

        visited2[curr] = true;
        cout << curr << " ";

        for (int i = adjList[curr].size() - 1; i >= 0; i--)
        {
            const int next = adjList[curr][i];
            if (!visited2[next])
            {
				s.push(next);
            }
        }
    }
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
	bfs(V);

    return 0;
}
