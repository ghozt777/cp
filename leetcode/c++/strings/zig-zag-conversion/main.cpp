// link : https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() == 1) return s ;
        vector<string> arr(numRows , "") ;
        int i = 0 ;
        int c = 0 ;
        bool rev = false ;
        while(i < s.length()){
            if(rev){
                if(c == 0){
                    arr[c] += s[i] ;
                    ++i ;
                    ++c ;
                    rev = false ;
                }
                else{
                    arr[c] += s[i] ;
                    ++i ;
                    --c ;
                }
            }
            else{
                if(c == numRows - 1){
                    arr[c] += s[i] ;
                    ++i ;
                    --c ;
                    rev = true ;
                }
                else{
                    arr[c] += s[i] ;
                    ++i ;
                    ++c ;
                }
            }
        }
        string res = "" ;
        for(string x : arr) res += x ;
        return res ;
    }
};