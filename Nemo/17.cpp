vector<int> inputNum;
vector<string> result;
map<int, string> info
{
 {2, "abc"}
 , {3, "def"}
 , {4, "ghi"}
 , {5, "jkl"}
 , {6, "mno"}
 , {7, "pqrs"}
 , {8, "tuv"}
 , {9, "wxyz"}
};

void func1(int depth, string s)
{
    if (depth >= inputNum.size())
    {
        result.push_back(s);
        return;
    }
    else
    {
        for (int i = 0; i < info[inputNum[depth]].size(); ++i)
        {
            func1(depth+1, s + info[inputNum[depth]][i]);
        }
    }
}


class Solution {
public:
vector<string> letterCombinations(string digits) {
    result.clear();
    inputNum.clear();
    
    if (digits.empty())
        return result;

    for (const auto& digit : digits)
    {
        inputNum.push_back(digit - 48);
    }

    for (int i = 0; i < info[inputNum[0]].size(); ++i)
    {
        string s = "";
        s += info[inputNum[0]][i];
        func1(1, s);
    }

    return result;
}

};
