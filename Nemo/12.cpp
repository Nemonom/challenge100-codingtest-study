class Solution {
public:
    string intToRoman(int num) {
         map<int, string> info2 = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, };
    string result;

    int cnt = 0;
    while (cnt < 4 && num > 0)
    {
        int a = num % 10;
        string save;

        if (a != 0)
        {
            if (a == 9)
            {
                save += (info2[1 * pow(10, cnt)]);
                save += (info2[10 * pow(10, cnt)]);
            }
            else
            {
                int i_cnt = a % 5;
                int v_cnt = a / 5;

                if (v_cnt != 0)
                    save += (info2[5 * pow(10, cnt)]);

                for (int i = 0; i < i_cnt; ++i)
                    save += (info2[1 * pow(10, cnt)]);
            }
        }
        result = save + result;
        cnt++;
        num /= 10;
    }
    return result;
    }
};
