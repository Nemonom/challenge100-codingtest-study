#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    
    for (const auto& num : numbers)
      answer -= num;
    
    return answer;
}
