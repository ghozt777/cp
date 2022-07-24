// link: https://leetcode.com/problems/matchsticks-to-square/

class Solution {
    bool dfs(vector<int>&matchsticks,vector<int>&s,int curr,int t){
        if(curr>=matchsticks.size())return s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3];
        for(int i=0;i<4;i++){
            if(s[i]+matchsticks[curr]<=t){ // optimization
                s[i]+=matchsticks[curr];
                if(dfs(matchsticks,s,curr+1,t)) return true;
                s[i]-=matchsticks[curr];
            } 
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4)return false;
        vector<int> s(4,0);  
        sort(matchsticks.begin(),matchsticks.end(),[](const int&a,const int&b){ // optimization -> reverse sort
            return a>b;
        });
        return dfs(matchsticks,s,0,sum/4);
    }
};