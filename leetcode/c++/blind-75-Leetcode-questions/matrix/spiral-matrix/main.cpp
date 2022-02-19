// link : https://leetcode.com/problems/spiral-matrix/

/*
    IDEA : Try to visualize the traversal on pen and paper
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rStart = 0 ;
        int rEnd = matrix.size() - 1 ;
        int cStart = 0 ;
        int cEnd = matrix[0].size() - 1 ;
        vector<int> ans ;
        while(cStart <= cEnd && rStart <= rEnd){
            for(int i = cStart ; i <= cEnd ; i++) ans.push_back(matrix[rStart][i]) ;
            ++rStart ;
            if(rStart > rEnd) break ;
            for(int i = rStart ; i <= rEnd ; i++) ans.push_back(matrix[i][cEnd]) ;
            --cEnd ;
            if(cStart > cEnd) break ;
            for(int i = cEnd ; i >= cStart ; i--) ans.push_back(matrix[rEnd][i]) ;
            --rEnd ;
            if(rStart > rEnd) break ;
            for(int i = rEnd ; i >= rStart ; i--) ans.push_back(matrix[i][cStart]) ;
            ++cStart ;
            if(cStart > cEnd) break ;
        }
        return ans ;
    }
};