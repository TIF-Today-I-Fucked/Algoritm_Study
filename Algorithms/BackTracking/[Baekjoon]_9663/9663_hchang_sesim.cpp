/*
	백준 주소 : https://www.acmicpc.net/problem/9663
	난이도 : 골드4
	문제 이름 : N-Queen
*/

#include <iostream>

using namespace std;
const int	MAX = 15;
int			arr[MAX];
int			res;
int			N;

bool	check(const int& cur_x, const int& cur_y)
{
	for (int x(0); x < N; ++x)
	{
		if (arr[x] == 0)
			continue;
		const int	cross_pos = cur_y - (arr[x] - 1);
		if (cur_x == (x - cross_pos) || cur_x == (x + cross_pos))
		{
			return (false);
		}
	}
	return (true);
}

void	nQueen(const int y)
{
	if (y == N)
	{
		res++;
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0 && check(i, y))
		{
			arr[i] = y + 1;
			nQueen(y + 1);
			arr[i] = 0;
		}
	}
}

int	main()
{
	cin >> N;
	nQueen(0);
	cout << res << endl;
}

//=================================================================================================
// gpt 10queen
//#include <iostream>
//using namespace std;

//const int N = 10;
//int board[N];
//int n;
//int cnt;

//bool check(int row, int col) {
//    for (int i = 1; i < row; ++i) {
//        if (board[i] == col || row - i == abs(col - board[i])) {
//            return false;
//        }
//    }
//    return true;
//}

//void dfs(int row) {
//    if (row > n) {
//        ++cnt;
//        return;
//    }
//    for (int col = 1; col <= n; ++col) {
//        if (check(row, col)) {
//            board[row] = col;
//            dfs(row + 1);
//            board[row] = 0;
//        }
//    }
//}

//int main() {
//    cin >> n;
//    dfs(1);
//    cout << cnt << endl;
//    return 0;
//}