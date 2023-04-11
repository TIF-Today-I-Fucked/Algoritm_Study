/*
	백준 주소 : https://www.acmicpc.net/problem/1325
	난이도 : 실버1
	문제 이름 : 효율적인 해킹
*/

#include <functional>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

vector<int>	arr[10001];

int	bfs(const int& start)
{
	queue<int>	q;
	bool		visited[10001] = {0, };
	int			res(0);

	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		const int cur = q.front();
		q.pop();
		for (int i(0); i < arr[cur].size(); ++i)
		{
			const int next = arr[cur][i];
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
				res++;
			}
		}
	}
	return (res);
}

int	main()
{
	int	node, n;
	cin >> node >> n;

	vector<int>	ans(node + 1);
	for (int i(1); i <= n; ++i)
	{
		int	a, b;
		cin >> a >> b;
		arr[b].push_back(a);
	}
	for (int i(1); i <= node; ++i)
	{
		ans[i] = bfs(i);
	}
	const int max = *max_element(ans.begin(), ans.end());
	for (int i(0); i < ans.size(); ++i)
	{
		if (ans[i] == max)
			cout << i << " ";
	}

	//해킹 가능한 최대 컴퓨터 수 구하기
    int maxHack = -1; 
    for (int i = 1; i < ans.size(); i++)
	{
        if (ans[i] > maxHack) {
            maxHack = ans[i];
        }
    }
	cout << "=================\n";
	cout << ans.capacity() << endl;
	cout << ans.size() << endl;
	cout << ans.at(6) << endl;

	cout << "------------------\n";
    //maxHack에 해당하는 컴퓨터 번호 모두 출력
    for (int i = 1; i < ans.size(); i++)
	{
        if (ans[i] == maxHack) {
            std::cout << i << " ";
        }
    }
}