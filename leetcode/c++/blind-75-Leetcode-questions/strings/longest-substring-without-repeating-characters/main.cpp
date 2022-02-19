// link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen ;
        int start = 0 ;
        int curr = 0 ;
        int res = 0 ;
        while(curr < s.size()){
            if(seen.find(s[curr]) == seen.end()){
                seen.insert(s[curr]) ;
                res = max(res , (int)seen.size()) ;
                ++curr ;
            }
            else{
                seen.erase(s[start++]) ;
            }
        }
        return res ;
    }
};