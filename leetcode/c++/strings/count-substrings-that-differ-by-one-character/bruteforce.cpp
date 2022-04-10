// link : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0 ;
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = 0 ; j < t.length() ; j++){
                int miss = 0 ;
                for(int curr = 0 ; i + curr < s.length() && j + curr < t.length() ; curr++){
                    if(s[i + curr] != t[j + curr]) ++miss ;
                    if(miss > 1) break ;
                    res += miss ;
                }
            }
        }
        return res ;
    }
};