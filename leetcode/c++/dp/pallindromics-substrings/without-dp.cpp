// link : https://leetcode.com/problems/palindromic-substrings/submissions/
// TC: O(n.n) = O(n^2) -> faster than dp solution
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.length() ;
        int res = 0 ;
        for(int i = 0 ; i < n ; i++){
            int start = i ;
            int end = i ;
            // for odd length substring -> consider each char at i -> (string of length 1) as the middle point in the substring
            while(start >= 0 && end < n && s[start] == s[end]) --start , ++end , ++res ;
            start = i ;
            end = i + 1 ;
            // for even length substring -> start with a string of length 2 -> expand outwards
            while(start >= 0 && end < n && s[start] == s[end]) --start , ++end , ++res ;
        }
        return res ;
    }
};