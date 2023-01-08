// link: https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0 ;
        for(char x : word){
            cnt += x == toupper(x) ;
        }

        return cnt == 0 || cnt == word.length() || (cnt == 1 && word[0] == toupper(word[0])) ;
    }
};