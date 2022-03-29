// link : https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
    int start , maxLength ;
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s ;
        start = 0 ;
        maxLength = 0 ;
        for(int i = 0 ; i < s.length() - 1 ; i++){ // consider every i to be the mid point and expand in both directions 
            expand(s , i , i) ; // for odd lengths
            expand(s , i , i + 1) ; // for even lengths
        }
        return s.substr(start , maxLength) ;
    }
     void expand(string s , int lo , int hi){
        int i(lo) , j(hi) ;
        while(i >= 0 && j < s.length() && s[i] == s[j]) --i , ++j ;
        if(maxLength < j - i - 1){ // basically ((j - 1) - (i + 1) + 1) we shrink the border characters as they are mismatched
            maxLength = j - i - 1 ;
            start = i + 1; // remove the last mismatched character
        }
     }
};