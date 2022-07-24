// link:https://leetcode.com/problems/interleaving-string/

class Solution {
    int dp[101][101];
    bool check(string &s1,string &s2,string &s3,int i,int j){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s1.length() and j==s2.length()) return true;
        bool res=false;
        int k=i+j;
        if(i!=s1.length()&&s1[i]==s3[k]) res|=check(s1,s2,s3,i+1,j);
        if(j!=s2.length()&&s2[j]==s3[k]) res|=check(s1,s2,s3,i,j+1);
        return dp[i][j]=res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        memset(dp,-1,sizeof(dp));
        return check(s1,s2,s3,0,0);
    }
};