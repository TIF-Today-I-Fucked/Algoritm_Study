/*
	백준 주소 : https://www.acmicpc.net/problem/2178
	난이도 : 실버1
	문제 이름 : 미로 찾기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

std::vector<std::string>	mapp;
bool						visited[100][100];
int							final_x, final_y;
// 4이면 0 ~ 3까지
// 6이면 0 ~ 5까지
std::queue<std::pair<int, int> >	q;

int	bfs(int x, int y, int steps)
{
	int step(1);
	while (true)
	{
		int size = q.size();
		while(size--)
		{
			std::pair<int, int> cur = q.front();
			if (cur.first == final_x && cur.second == final_y)
				return step;
			visited[cur.first - 1][cur.second - 1] = true;
			if (cur.first + 1 <= final_x && visited[cur.first][cur.second - 1] == 0 && mapp[cur.first][cur.second - 1] == '1')
			{
				visited[cur.first][cur.second - 1] = true;
				q.push(std::make_pair(cur.first + 1, cur.second));
			}
			if (cur.second + 1 <= final_y && visited[cur.first - 1][cur.second] == 0 && mapp[cur.first - 1][cur.second] == '1')
			{
				visited[cur.first - 1][cur.second] = true;
				q.push(std::make_pair(cur.first, cur.second + 1));
			}
			if (cur.first - 1 > 0 && visited[cur.first - 2][cur.second - 1] == 0 && mapp[cur.first - 2][cur.second - 1] == '1')			
			{
				visited[cur.first - 2][cur.second - 1] = true;
				q.push(std::make_pair(cur.first - 1, cur.second));
			}
			if (cur.second - 1 > 0 && visited[cur.first - 1][cur.second - 2] == 0 && mapp[cur.first - 1][cur.second - 2] == '1')
			{
				visited[cur.first - 1][cur.second - 2] = true;
				q.push(std::make_pair(cur.first, cur.second - 1));
			}
			q.pop();
		}
		step++;
	}
}

int main()
{

	std::cin >> final_x >> final_y;
	for (int i = 0; i < final_x; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		mapp.push_back(tmp);
	}

	q.push(std::make_pair(1, 1));
	visited[0][0] = true;

	std::cout << bfs(1, 1, 1) << std::endl;
	//std::cout << "=============================\n";
	//	for (int i = 0; i < final_x; i++)
	//	{
	//		for (int j = 0; j < final_y; j++)
	//		{
	//			//std::cout << visited[i][j] << " ";
	//			std::cout << mapp[i][j] << " ";

	//		}
	//		std::cout << std::endl;
	//	}
	//std::cout << "=============================\n";

	//std::cout << "=============================\n";
	//	for (int i = 0; i < final_x; i++)
	//	{
	//		for (int j = 0; j < final_y; j++)
	//		{
	//			std::cout << visited[i][j] << " ";
	//			//std::cout << mapp[i][j] << " ";

	//		}
	//		std::cout << std::endl;
	//	}
	//std::cout << "=============================\n";
}