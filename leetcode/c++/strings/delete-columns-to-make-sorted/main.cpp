// link: https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n = strs.size() , m = strs[0].length() ;
        int res = 0 ;
        for(int i = 0 ; i < m ; i++){
            char last = strs[0][i] ;
            for(int j = 1 ; j < n ; j++){
                if(strs[j][i] < last){
                    ++res ;
                    break ;
                }
                else last = strs[j][i] ;
            }
        }
        return res; 
    }
};