int lengthOfLongestSubstring(string s) {
    map<char, string> st;
    int i_max = 0;

    for (const auto& ch : s)
    {
        auto it = st.begin();
        while (it != st.end())
        {
            if (it->second.find(ch) != string::npos)
            {
                i_max = max(i_max, (int)it->second.size());
                st.erase(it++);
            }
            else
            {
                it->second += ch;
                it++;
            }
        }
       

        if (st.find(ch) == st.end())
        {
            st[ch] = ch;
        }
    }

    for (const auto& sts : st)
    {
        i_max = max(i_max, (int)sts.second.size());
    }
    return i_max;
}
