// link : https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int n = rating.size() ;
        vector<vector<int>> dp_inc(4 , vector<int>(n , 0)) ;
        vector<vector<int>> dp_dec(4 , vector<int>(n , 0)) ;
        for(auto &x : dp_inc[1]) x = 1 ;
        for(auto &x : dp_dec[1]) x = 1 ;
        for(int size = 2 ; size <= 3 ; size++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < i ; j++){
                    if(rating[j] < rating[i]) dp_inc[size][i] += dp_inc[size - 1][j] ;
                    if(rating[j] > rating[i]) dp_dec[size][i] += dp_dec[size - 1][j] ;
                }
            }
        }
        int res = 0 ;
        for(int x : dp_inc[3]) res += x ;
        for(int x : dp_dec[3]) res += x ;
        return res ;
    }
};