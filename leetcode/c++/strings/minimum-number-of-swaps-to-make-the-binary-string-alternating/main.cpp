// link : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

class Solution
{
    int misplaced(string s, char check)
    {
        int res = 0;
        for (int i = 0; i < s.size(); i += 2)
            res += s[i] != check;
        return res;
    }

public:
    int minSwaps(string s)
    {
        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = count(s.begin(), s.end(), '1');
        if (abs(cnt0 - cnt1) > 1)
            return -1;
        if (cnt0 > cnt1)
            return misplaced(s, '0');
        else if (cnt1 > cnt0)
            return misplaced(s, '1');
        else
            return min(misplaced(s, '0'), misplaced(s, '1'));
    }
};