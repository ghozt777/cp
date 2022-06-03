// link : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution {
public:
    int numSplits(string s) {
        int res = 0  ;
        unordered_set<char> a ;
        unordered_map<char , int> b ;
        for(char x : s) ++b[x] ;
        for(int i = 0 ; i < s.length() ; i++){
            --b[s[i]] ;
            a.insert(s[i]) ;
            if(!b[s[i]]) b.erase(s[i]) ;
            if(a.size() == b.size()) ++res ;
        }
        return res ;
    }
};

/*
    // bruteforce TLE
    
    class Solution {
    bool c(int x , string & s){
        unordered_set<char> s1 ;
        unordered_set<char> s2 ;
        for(int i = 0 ; i <= x ; i++) s1.insert(s[i]) ;
        for(int i = x + 1 ; i < s.length() ; i++) s2.insert(s[i]) ;
        return s1.size() == s2.size() ;
    }
public:
    int numSplits(string s) {
        int res = 0  ;
        for(int i = 1 ; i < s.length() ; i++) if(c(i , s)) ++res ;
        return res ;
    }
};
*/