// Longest Common Subsequence (LCS)

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m){
    if(!n || !m) return 0;
    if(s1[n - 1] == s2[m - 1]) return 1 + lcs(s1, s2, n - 1, m - 1);
    else return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}

vector<vector<int>> dp(1000, vector<int>(1000, -1));

int lcsMemo(string s1, string s2, int n, int m){
    if(dp[n][m] != -1) return dp[n][m];
    int res;
    if(!n || !m) res = 0;
    if(s1[n - 1] == s2[m - 1]) res = 1 + lcs(s1, s2, n - 1, m - 1);
    else res = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    dp[n][m] = res;
    return dp[n][m];
}


int main(){
    string s1 = "AXYZJHDSJHJSHJSDSD";
    string s2 = "BAZSHSJDHJKSJKDS";
    cout << lcsMemo(s1, s2, s1.length(), s2.length()) << endl;
    cout << lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}