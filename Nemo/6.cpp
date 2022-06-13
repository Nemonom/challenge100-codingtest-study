string convert(string s, int numRows) {    
    if (numRows == 1)
        return s;

    string result;
    for (int i = 1; i <= numRows; ++i)
    {
        int curBlock = 0;
        while (i + (2 * numRows - 2) * curBlock <= s.size())
        {
            int first = i + (2 * numRows - 2) * curBlock; // start
            int second = first + 2 * (numRows - i); // next
            
            result += s[first - 1];
            if (second <= s.size() && i != 1 && i != numRows)
              result += s[second - 1];
            curBlock++;
        }
    }
    return result;
}
