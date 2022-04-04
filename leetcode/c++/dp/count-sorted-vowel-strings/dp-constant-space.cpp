// link : https://leetcode.com/problems/count-sorted-vowel-strings/ 

class Solution {
public:
    int countVowelStrings(int n) {
        int a =1 , e = 1 , i = 1 , o = 1 , u = 1 ;
        for(int k = 2 ; k <= n ; k++){
            a = a + e + i + o + u ;
            e = e + i + o + u ;
            i = i + o + u ;
            o = o + u ;
            u = u ;
        }
        return a + e + i + o + u ;
    }
};