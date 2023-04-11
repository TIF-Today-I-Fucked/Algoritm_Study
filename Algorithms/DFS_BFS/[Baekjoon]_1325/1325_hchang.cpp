/*
	백준 주소 : https://www.acmicpc.net/problem/1325
	난이도 : 실버1
	문제 이름 : 효율적인 해킹
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX 10000
std::vector<int>					v[MAX];
std::vector<std::pair<int, int> >	res;

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int	dfs(int start)
{
	bool	visited[MAX] = {0, };
	int cnt(0);
	std::stack<int>	st;

	st.push(start);
	while (!st.empty())
	{
		const int top = st.top();
		st.pop();
		if (visited[top])
			continue;
		visited[top] = true;
		for(int i = 0; i < v[top].size(); i++)
		{
			if (!visited[v[top][i]])
			{
				st.push(v[top][i]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int node, edge;
	std::cin >> node >> edge;

	for (int i = 1; i <= edge; i++)
	{
		int tmp1, tmp2;
		std::cin >> tmp1 >> tmp2;
		v[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= node; i++)
	{
		std::pair<int, int> tmp;
		tmp.first = i;
		tmp.second = dfs(i);
		res.push_back(tmp);
	}

	//std::sort(res.begin(), res.end(), compare);

	//int tmp = res[0].second;
	//for (int i = 0; i < node; i++)
	//{
	//	if (tmp != res[i].second)
	//		break;
	//	std::cout << res[i].first << " ";
	//}
}