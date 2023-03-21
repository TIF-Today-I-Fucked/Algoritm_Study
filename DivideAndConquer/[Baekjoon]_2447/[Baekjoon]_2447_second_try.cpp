#include <iostream>

bool	checkMid(int num, int x, int y)
{
	int	m_y = y / num;
	int	m_x = x / num;
	
	if (x == 0 && y == 0)
		return false;
	else if ((x == (1 + (num / 3) * m_x)
		&& y == (1 + (num / 3) * m_y))
		|| ((num / 3 >= y && ((num / 3) * 2) - 1 < y)
			&& (num / 3 >= x && ((num / 3) * 2) - 1 < x)))
		return true;	
	return false;
}

void star(const int& size, int num, int x, int y)
{
	std::cout << "x : " << x << " y : " << y << std::endl;
	if (num == 1)
	{
		if (checkMid(num, x, y))
			std::cout << " ";
		else
			std::cout << "*";
	}
	else
	{
		if (num == size)
		{
			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					star(size, num / 3, j, i);
				}
				std::cout << std::endl;
			}
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				star(size, num / 3, j + (num / 3) * j, y);
			}
		}
	}
}

int main() {
    int num;
    std::cin >> num;
	star(num, num, 0, 0);
    
}