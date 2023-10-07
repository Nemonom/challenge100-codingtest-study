#include<iostream> 
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> connectInfo;
int isInfected[101];

void func(int k)
{
	if (isInfected[k])
	{
		return;
	}

	isInfected[k] = true;

	for (const auto& info : connectInfo[k])
	{
		func(info);
	}
}

int main()
{
	std::fill_n(isInfected, 101, false);

	int comNum{ 0 }, comNet{ 0 };
	cin >> comNum >> comNet;

	for (int i = 0; i < comNet; ++i)
	{
		int tempF{ 0 }, tempS{ 0 };
		cin >> tempF >> tempS;
		connectInfo[tempF].push_back(tempS);
		connectInfo[tempS].push_back(tempF);
	}

	func(1);

	int cnt = 0;
	for (int i = 2; i < 101; ++i)
	{
		cnt += isInfected[i];
	}

	cout << cnt;

	return 0;
}
