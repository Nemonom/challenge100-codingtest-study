#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> except;

    for (const auto& num : nums)
    {
        except.insert(num);
    }

    int maxNum = nums.size() / 2;
    int minNum = except.size();

    return min(minNum, maxNum);
}
