// link: https://leetcode.com/problems/regions-cut-by-slashes/

// IDEA: Floodfill

class Solution {
    void dfs(vector<vector<int>> & arr, int i,int j){
        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 0) return ;
        arr[i][j] = 0 ;
        dfs(arr,i + 1 , j);
        dfs(arr,i - 1 , j);
        dfs(arr,i , j + 1);
        dfs(arr,i , j - 1);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size() ;
        vector<vector<int>> arr(3 * n , vector<int>(3 * n , 0)) ;
        for(int i = 0 ; i < n ; i++){
            string &x = grid[i] ;
            // process for ith row
            vector<char> cells ;
            for(int j = 0 ; j < x.length() ; j++){
                if(x[j] == ' '){
                    // empty space -> connected component
                    arr[3*i][3*j] = arr[3*i + 1][3*j] = arr[3*i + 2][3*j] = arr[3*i][3*j + 1] = arr[3*i + 1][3*j + 1] = arr[3*i + 2][3*j + 1] = arr[3*i][3*j + 2] = arr[3*i + 1][3*j + 2] = arr[3*i + 2][3*j + 2] = 1;
                }
                if(x[j] == '\\'){
                    arr[3*i][3*j + 1] = arr[3*i][3*j + 2] = arr[3*i + 1][3*j + 2] = arr[3* i + 1][3*j] = arr[3*i +2][3*j] = arr[3*i + 2][3*j + 1] = 1 ;
                }
                else{
                    arr[3*i][3*j] = arr[3*i][3*j + 1] = arr[3*i + 1][3*j] = arr[3*i + 1][3*j + 2] = arr[3*i + 2][3*j + 2] = arr[3*i + 2][3*j + 1] = 1 ;
                }
            }
        }

        int res = 0 ;

        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = 0 ; j < arr[i].size() ; j++){
                if(arr[i][j]){
                    ++res;
                    dfs(arr,i,j);
                }
            }
        }
        
        return res;
    }
};