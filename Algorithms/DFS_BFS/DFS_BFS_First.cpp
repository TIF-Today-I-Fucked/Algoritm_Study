#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

void	dfs(std::vector<int> v[], const int& node, const int& first)
{
	std::vector<bool>	isVisited(node + 1);
	std::stack<int>		dfs_st;

	dfs_st.push(first);
	isVisited[first] = true;
	std::cout << first;
	while (!dfs_st.empty())
	{
		if (v[dfs_st.top()].empty())
		{
			dfs_st.pop();
		}
		else if (isVisited[v[dfs_st.top()].at(0)] == false)
		{
			dfs_st.push(v[dfs_st.top()].at(0));
			std::cout << " " << dfs_st.top();
			isVisited[dfs_st.top()] = true;
		}
		else // visited인 상태
		{
			v[dfs_st.top()].erase(v[dfs_st.top()].begin());
		}
	}
	std::cout << std::endl;
}

void	bfs(std::vector<int> v[], const int& node, const int& first)
{
	std::vector<bool>	isVisited(node + 1);
	std::queue<int>		bfs_q;

	bfs_q.push(first);
	isVisited[first] = true;
	std::cout << first;
	while(!bfs_q.empty())
	{
		while (!v[bfs_q.front()].empty())
		{
			//std::cout << " is tha tyou ?\n";
			int tmp = v[bfs_q.front()].front();
			if (isVisited[tmp] == false)
			{
				bfs_q.push(tmp);
				isVisited[tmp] = true;
				std::cout << " " << tmp;
			}
			v[bfs_q.front()].erase(v[bfs_q.front()].begin());
		}
		bfs_q.pop();
	}
	std::cout << std::endl;
}

int main()
{
	int node, edge, first;
	std::cin >> node >> edge >> first;

	std::vector<int>	v[node + 1]; // 1부터 index 시작
	std::vector<int>	v2[node + 1]; // 1부터 index 시작

	for(int i = 1; i <= edge; i++)
	{
		int tmp1, tmp2;
		std::cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
		v2[tmp1].push_back(tmp2);
		v2[tmp2].push_back(tmp1);
	}

	for(int i = 1; i <= node; i++)
	{
		std::sort(v[i].begin(), v[i].end());
		std::sort(v2[i].begin(), v2[i].end());
	}

	dfs(v, node, first);
	bfs(v2, node, first);
}