#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

const int 			MAX = 10001;
int 				N, M;
std::vector<int>	v[MAX];
bool				visited[MAX];

// N개 컴퓨터
// M개 연결 

int	bfs(int start)
{
	int res(0);
	std::queue<int>	q;
	visited[start] = true;
	q.push(start);

	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int q_front = q.front();
			q.pop();
			for(int i = 0; i < v[q_front].size(); i++)
			{
				if (visited[v[q_front][i]] == false)
				{
					q.push(v[q_front][i]);
					visited[v[q_front][i]] = true;
					res++;
				}
			}
		}
	}
	return res;
}

int main()
{
	std::vector<int>	res;
	std::vector<int>	final_res;
	std::cin >> N >> M;
	v->resize(MAX, 0);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		std::cin >> x >> y;
		v[y].push_back(x);
	}


	for (int i = 1; i <= N; i++)
	{
		res.push_back(bfs(i));
		memset(visited, 0, sizeof(visited));
	}

	int max = *max_element(res.begin(), res.end());
	//std::sort(res.begin(), res.end(), std::grea<int>());
	for (int i = 0; i < res.size(); i++)
	{
		if (max == res[i])
		{
			std::cout << i + 1 << std::endl;
		}
	}

	

	//for (int i = 1; i < N; i++)
	//{
	//	std::cout << i << " 번쨰 : "; 
	//	for(int j = 0; j < v[i].size(); j++)
	//	{
	//		std::cout << v[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

}