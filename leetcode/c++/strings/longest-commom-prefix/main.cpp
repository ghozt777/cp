// link: https://leetcode.com/problems/longest-common-prefix/submissions/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0 ; 
        string pre = "" ;
        char toCheck = strs[0][0] ;
        while(1){
            bool b = false ;
            for(int j = 0 ; j < strs.size() ; j++){
                if(i >= strs[j].length()){
                    b = true ;
                    break ;
                }
                if(strs[j][i] != toCheck){
                    b = true ;
                    break ;
                }
            }
            if(b) break ;
            pre += strs[0][i] ;
            ++i ;
            if(i >= strs[0].length()) break ;
            toCheck = strs[0][i] ;
        }
        return pre ;
    }
};