#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for (auto& text : new_id)
    {
        if ('A' <= text && text <= 'Z')
        {
            answer.push_back(text + 32);
        }
        else if (('0' <= text && text <= '9')
            || ('a' <= text && text <= 'z')
            || ('-' == text || '_' == text || '.' == text))
        {
            if ('.' == text && answer.empty() == false && answer.back() != '.')
            {
                answer.push_back(text);
            }
            else if ('.' != text)
            {
                answer.push_back(text);
            }
        }

        if (answer.size() >= 15)
            break;
    }

    if (answer.empty())
        answer.push_back('a');

    if (answer.back() == '.')
        answer.pop_back();
      
    while (answer.size() < 3)
        answer.push_back(answer.back());

    return answer;
}
