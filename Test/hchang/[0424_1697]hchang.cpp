#include <iostream>
#include <queue>

const int 		MAX = 100001;
int				start, des;
std::queue<int>	q;
bool			visited[MAX];

int	bfs(void)
{
	int res(0);
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int tmp = q.front();
			//std::cout << "tmp is : " << tmp << std::endl;
			q.pop();
			if (tmp == des)
				return res;
			if (tmp - 1 >= 0 && visited[tmp - 1] == false)
			{
				visited[tmp - 1] = true;
				q.push(tmp - 1);
			}
			if (tmp * 2 < MAX && visited[tmp * 2] == false)
			{
				visited[tmp * 2] = true;
				q.push(tmp * 2);
			}
			if (tmp + 1 < MAX && visited[tmp + 1] == false)
			{
				visited[tmp + 1] = true;
				q.push(tmp + 1);
			}
		}
		res++;
	}
	return res;
}

int main()
{
	std::cin >> start >> des;

	q.push(start);
	visited[start] = true;
	std::cout << bfs() << std::endl;
}