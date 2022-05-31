#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

class ReportInfo
{
public:
    ReportInfo() { sendUserList_.clear(); numReport_ = 0; }
    set<string> sendUserList_;
    int numReport_;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    map<string, ReportInfo> personalInfo; // name, info

    for (auto& reportInfo : report)
    {
        istringstream iss(reportInfo);
        string a, b;
        iss >> a >> b;
        auto it = personalInfo[a].sendUserList_.insert(b);
        if (it.second)
            personalInfo[b].numReport_++;
    }

    vector<int> answer;

    for (const auto& id : id_list)
    {
        int cnt = 0;
        for (const auto& cntReport : personalInfo[id].sendUserList_)
        {
            if (personalInfo[cntReport].numReport_ >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
