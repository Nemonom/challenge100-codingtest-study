#include <iostream> 
#include <array>
#include <math.h>
#include <queue>

using namespace std;

int mapSize{ 0 }, maxHeight{ 0 }, result{ 0 };
int mapData[101][101];
bool isChecked[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main()
{
	fill(&mapData[0][0], &mapData[0][0] + 101 * 101, 999);
	cin >> mapSize;

	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			cin >> mapData[i][j];
			maxHeight = max(mapData[i][j], maxHeight);
		}
	}

	while (maxHeight--)
	{
		fill(&isChecked[0][0], &isChecked[0][0] + 101 * 101, false);

		int cnt{ 0 };
		for (int i = 0; i < mapSize; ++i)
		{
			for (int j = 0; j < mapSize; ++j)
			{
				if (isChecked[i][j]
					|| maxHeight >= mapData[i][j])
					continue;

				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				isChecked[i][j] = true;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int dirX = cur.second + dx[dir];
						int dirY = cur.first + dy[dir];
					
						if ((dirX < 0 || dirY < 0 || dirX >= mapSize || dirY >= mapSize)
							|| maxHeight >= mapData[dirY][dirX]
							|| isChecked[dirY][dirX])
							continue;

						isChecked[dirY][dirX] = true;
						q.push(make_pair(dirY, dirX));
					}
				}
				cnt++;
			}
		}
		result = max(cnt, result);
	}

	cout << result;

	return 0;
}
