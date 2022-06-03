// link : https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution {
    int dp[1000000] ;
    int getPower(int n){
        if(dp[n]) return dp[n] ;
        if(n == 1) return 0 ;
        if(n % 2 == 0) return  dp[n] = 1 + getPower(n / 2) ;
        else return dp[n] = 1 + getPower(3 * n + 1) ;
    }
public:
    int getKth(int lo, int hi, int k) {
        memset(dp , 0 , sizeof(dp)) ;
        vector<pair<int , int>> res ;
        for(int i = lo ; i <= hi ; i++) res.push_back({ getPower(i) , i }) ;
        sort(res.begin() , res.end()) ;
        return res[k - 1].second ;
    }
};