// link : https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
    vector<char> vowels = {'a' , 'e' , 'i' , 'o' , 'u'} ;
    int res ;
    void helper(int n , char last){
        if(n == 0){
            ++res ;
            return ;
        }
        for(char v : vowels) 
            if(v <= last) 
                helper(n - 1 , v) ;
    }
public:
    int countVowelStrings(int n) {
        res = 0 ; 
        helper(n , 'z') ;  // 'z' so that every vowel can be taken into consideration for the initial call (as all of the vowels(ASCII) are less than 'z')
        return res ;
    }
};