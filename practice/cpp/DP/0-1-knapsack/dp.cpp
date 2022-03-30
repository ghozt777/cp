#include<bits/stdc++.h>
using namespace std;

// using tabulation or bottom up approach
// TC: O(limit x size_of_array) 
int solve(vector<int>& weights, vector<int>& values, int limit){
    const int n = values.size();
    int dp[n + 1][limit + 1];
    for(int i = 0; i <= limit; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= limit; j++){
            if(weights[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max((values[i - 1] + dp[i - 1][j - weights[i - 1]]), dp[i - 1][j]);
        }
    }
    return dp[n][limit];
}

int main(){
    vector<int> values = { 10, 40 , 30 , 50 };
    vector<int> weights = { 5, 4, 6, 3 };
    int limit = 10;
    cout << solve(weights, values, limit) << endl;
    return 0;
}