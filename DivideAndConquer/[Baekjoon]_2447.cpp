/*
	백준 주소 : https://www.acmicpc.net/problem/1074
*/
#include <iostream>
using namespace std;
void star(int i, int j, int num)
{
    if((i / num)%3 == 1 && (j / num)%3 == 1) {
        cout << ' ';
    }
    else
    {
        if(num / 3 == 0)
            cout <<'*';
        else
            star(i,j,num/3);
    }
}
int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
            star(i,j,num);
        cout << '\n';
    }
}

/*
	백준 주소 : https://www.acmicpc.net/problem/1074
*/

#include <iostream>

void	printStar(int n)
{
	if (n < 1)
		return ;
	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
				std::cout << "@";
			else
			{
				if (n / 3 ==0)
					std::cout << "*";
				else
					printStar(n / 3);
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	int num;
	std::cin >> num;
	printStar(num);
}