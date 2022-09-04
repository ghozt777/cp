// link: https://leetcode.com/problems/01-matrix/

class Solution {
    bool atLeastOneZero(vector<vector<int>>&mat,int i,int j){
        int zeroes=0;
        if(i-1>=0)zeroes+=mat[i-1][j]==0;
        if(j-1>=0)zeroes+=mat[i][j-1]==0;
        if(i+1<mat.size())zeroes+=mat[i+1][j]==0;
        if(j+1<mat[0].size())zeroes+=mat[i][j+1]==0;
        return zeroes>=1;
    }
    bool ok(vector<vector<int>>&mat,int i,int j){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]==0) return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,int>> q;
        set<pair<int,int>> seen;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1&&atLeastOneZero(mat,i,j)){
                     q.push({i,j});
                    seen.insert({i,j});
                }
            }
        }
        vector<pair<int,int>> dirs={
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        int currDepth=1;
        while(!q.empty()){
            const int n=q.size();
            for(int i=0;i<n;i++){
                pair<int,int> curr=q.front();
                int x=curr.first,y=curr.second;
                q.pop();
                res[x][y]=currDepth;
                for(auto d:dirs){
                    int dx=x+d.first,dy=y+d.second;
                    if(ok(mat,dx,dy)&&seen.find({dx,dy})==seen.end()){
                        q.push({dx,dy});
                        seen.insert({dx,dy});
                    }
                }
            }
            ++currDepth;
        }
        return res;
    }
};