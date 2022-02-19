// link : https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        unordered_set<int> indices ;
        int total = m * n ;
        for(int i = 0 ; i < total ; i++) if(matrix[i / m][i % m] == 0) indices.insert(i) ;
        for(int x : indices){
            int row = x / m ; 
            int col = x % m ;
            for(int i = 0 ; i < m ; i++) matrix[row][i] = 0 ;
            for(int i = 0 ; i < n ; i++) matrix[i][col] = 0 ;
        }
    }
};