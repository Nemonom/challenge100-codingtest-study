string longestPalindrome(string s) {
    
    if (s.size() == 1) return s;
  
    int startPos = 0, endPos = 0;
    int max = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        int l_pos = i, r_pos = i;

        while (true)
        {
            if (r_pos + 1 < s.size() 
                && s[i] == s[r_pos + 1])
                r_pos++;
            else
                break;
        }

        while (true)
        {
            if (l_pos - 1 >= 0 && r_pos + 1 < s.size()
                && s[l_pos - 1] == s[r_pos + 1])
            {
                l_pos--;
                r_pos++;
            }
            else
                break;
        }

        if (r_pos - l_pos > max)
        {
            max = r_pos - l_pos;
            startPos = l_pos;
            endPos = r_pos;
        }
    }

    return s.substr(startPos, endPos - startPos + 1);
}
