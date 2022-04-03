// link : https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    bool isOk(vector<vector<int>>& matrix , int startI , int endI , int startJ , int endJ){
    for(int i = startI ; i <= endI ; i++)
        for(int j = startJ ; j <= endJ ; j++) 
            if(!matrix[i][j]) return false ;

    return true ;
}

    int countSquares(vector<vector<int>>& matrix){
        const int n = matrix.size() ;
        const int m = matrix[0].size() ;
        int c = min(n , m) ;
        int res = 0 ;
        for(int s = 1 ; s <= c ; s++){
            for(int i = 0 ; i < n - (s - 1) ; i++){
                for(int j = 0 ; j < m - (s - 1) ; j++){
                    if(isOk(matrix , i , i + (s - 1) , j , j + (s - 1))) ++res ;
                }
            }
        }
        return res ;
    }
};