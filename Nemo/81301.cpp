#include <string>
#include <vector>

using namespace std;

string convertStringToInt(string str)
{
    if (str == "zero")         return "0";
    else if (str == "one")     return "1";
    else if (str == "two")     return "2";
    else if (str == "three")   return "3";
    else if (str == "four")    return "4";
    else if (str == "five")    return "5";
    else if (str == "six")     return "6";
    else if (str == "seven")   return "7";
    else if (str == "eight")   return "8";
    else if (str == "nine")    return "9";
    return "";
}

int solution(string new_id) {

    string tempStr = "";
    string mainStr = "";
    for (auto& text : new_id)
    {
        if ('0' <= text && text <= '9')
        {
            mainStr.push_back(text);
        }
        else
        {
            tempStr.push_back(text);

            string check = convertStringToInt(tempStr);
            if (check != "")
            {
                mainStr += check;
                tempStr.clear();
            }
        }
    }

    int answer = stoi(mainStr);
    return answer;
}
