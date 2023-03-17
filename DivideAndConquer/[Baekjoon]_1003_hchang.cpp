/*
	백준 주소 : https://www.acmicpc.net/problem/1003
	난이도 : 실버3
*/

#include <iostream>
#include <vector>


void fino_num(int num, std::pair<int, int>& tmp)
{
	std::vector<std::pair<int, int > > answers;

	answers.push_back(std::pair<int, int>(1, 0));
	answers.push_back(std::pair<int, int>(0, 1));
	answers.push_back(std::pair<int, int>(1, 1));
	if (num < 3)
	{
		tmp.first = answers[num].first;
		tmp.second = answers[num].second;
		return ;
	}
	for (int i = 3; i <= num; i++)
	{
		tmp.first = answers[i - 1].first;
		tmp.second = answers[i - 1].second;
		tmp.first += answers[i - 2].first;
		tmp.second += answers[i - 2].second;
		answers.push_back(tmp);
		//std::cout << "just check " << tmp.first << " " << tmp.second << std::endl;
	}
}

int main()
{
	int num;
	std::cin >> num;
	int arr[num];
	std::vector<std::pair<int , int> > v;

	
	for (int i = 0; i < num; i++)
	{
		std::pair<int, int> tmp;
		std::cin >> arr[i];
		fino_num(arr[i], tmp);
		v.push_back(tmp);
	}
	
	for(std::vector<std::pair<int , int> >::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}
