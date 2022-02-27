// link : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets ;
        for(char x : s){
            if(x == '(' || x == '{' || x == '[') brackets.push(x) ;
            else{
                switch(x){
                    case ')' : 
                        if(!brackets.empty() && brackets.top() == '(') brackets.pop() ;
                        else return false ;
                        break ;
                    case '}' : 
                        if(!brackets.empty() && brackets.top() == '{') brackets.pop() ;
                        else return false ;
                        break ;
                    case ']' : 
                        if(!brackets.empty() && brackets.top() == '[') brackets.pop() ;
                        else return false ;
                        break ;
                    default : 
                        break ;
                }
            }
        }
        return brackets.size() == 0 ;
    }
};