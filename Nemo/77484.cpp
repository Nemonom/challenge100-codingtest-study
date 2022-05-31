#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
#define TOTAL_NUM 6

vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    int changeable = 0;
    int alreadyCorrect = 0;

    for (const auto& myNum : lottos)
    {
        if (myNum == 0)
            changeable++;
        else
        {
            for (const auto& winNum : win_nums)
            {
                if (winNum == myNum)
                    alreadyCorrect++;
            }
        }
    }

    vector<int> answer;

    int maxNum = max(1, changeable + alreadyCorrect);
    int minNum = max(1, alreadyCorrect);

    answer.push_back(TOTAL_NUM - maxNum + 1);
    answer.push_back(TOTAL_NUM - minNum + 1);

    return answer;
}
