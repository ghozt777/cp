// link : https://leetcode.com/problems/generate-parentheses/submissions/

class Solution {
    vector<string> res ;
    void reccur(int open , int closed , int n , string curr){
        if(curr.length() == 2 * n){
            res.push_back(curr) ;
            return ; 
        }
        if(open < n) reccur(open + 1 , closed , n , curr + "(") ;
        if(closed < open) reccur(open , closed + 1, n , curr + ")") ;
    }
public:
    vector<string> generateParenthesis(int n) {
        reccur(0,0,n,"") ;
        return res ;
    }
};