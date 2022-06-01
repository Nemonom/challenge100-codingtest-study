#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(const int num)
{
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {

    int sum = 0, answer = 0;

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        for (int j = i+1; j < nums.size() - 1; ++j)
        {
            for (int z = j+1; z < nums.size(); ++z)
            {
                sum = nums[i] + nums[j] + nums[z];

                if (isPrime(sum))
                    answer += 1;
            }
        }
    }

    return answer;
}
