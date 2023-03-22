#include<iostream>
#include<vector>

int main()
{
    unsigned int	num_of_stairs;
	bool			flag {false};

    std::cin >> num_of_stairs;
	if (num_of_stairs < 1)
		return 0;

    std::vector<int> scores(num_of_stairs);
    std::vector<int> record(num_of_stairs);

    for (int i = 1 ; i <= num_of_stairs ; i++)
        std::cin >> scores[num_of_stairs - i];
	

	/**
	* 연산은 두가지.
		1. 전전 기록과 현재 스코어를 더한 것과 전 기록을 비교해서 큰 것 가져가기
		2. 전 기록과 현재 스코어 더해서 가져가기

	  경우는 두가지
		1. flag : true -> 1번쨰 연산 수행 후, 전전기록과 현재스코어를 더한 것인 선택되면 flag==>false
		2. flag : false -> 2번쨰 연산 수행 후 flag==>true
	*/
	record.at(0) = scores.at(0);
	for (int i = 1 ; i < scores.size() ; i++)
	{
		if (flag == false)
		{
			record.at(i) = scores.at(i) + record.at(i - 1);
			flag = true;
		}
		else
		{
			// 전전 기록 + 현재 스코어가 더 큰 경우
			if (record.at(i - 1) < (record.at(i - 2) + scores.at(i)))
				flag = false;
			record.at(i) = flag ? record.at(i - 1) : (record.at(i - 2) + scores.at(i));
		}
	}
	std::cout << record[num_of_stairs - 1];
}