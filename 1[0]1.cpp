class Solution
{
public:
    int patternCount(string s)
    {
        int flag1 = 0;
        int flag0 = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1' && flag1 == 0 && flag0 == 0)
                flag1 = 1;
            else if (s[i] == '0' && flag1 == 1)
                flag0 = 1;
            else if (s[i] == '1' && flag1 == 1 && flag0 == 1)
            {
                cnt++;
                flag0 = 0;
            }
            else if (s[i] != '0' && s[i] != '1')
            {
                flag1 = 0;
                flag0 = 0;
            }
        }
        return cnt;
    }
};