// link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
*/

class Solution
{
    string getString(char x)
    {
        string s(1, x);
        return s;
    }
    unordered_map<int, string> hm = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };
    vector<string> res;
    void helper(string p, string up)
    {
        if (up == "")
            res.push_back(p);
        char digit = up[0];
        string letters = hm[digit - '0'];
        for (char x : letters)
        {
            helper(p + getString(x), up.substr(1));
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            vector<string> edgeCase;
            return edgeCase;
        }
        helper("", digits);
        return res;
    }
};