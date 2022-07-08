// link:https://leetcode.com/problems/rotting-oranges/

class Solution {
    int bfs(vector<vector<int>>&p,vector<vector<int>>&g){
        int res=-1;
        queue<vector<int>> q;
        for(auto x:p)q.push(x);
        while(!q.empty()){
            ++res;
            int n=q.size();
            cout<<"----------\n";
            cout<<"curr: "<<res<<endl;
            for(int i=0;i<n;i++){
                vector<int>curr=q.front();
                q.pop();
                int x=curr[0];
                int y=curr[1];
                cout<<x<<" "<<y<<endl;
                if(x+1<g.size()&&g[x+1][y]==1){
                    vector<int> v(2);
                    v[0]=x+1;
                    v[1]=y;
                    g[v[0]][v[1]]=2;
                    q.push(v);
                }
                if(x-1>=0&&g[x-1][y]==1){
                    vector<int> v(2);
                    v[0]=x-1;
                    v[1]=y;
                    g[v[0]][v[1]]=2;
                    q.push(v);
                }
                if(y+1<g[0].size()&&g[x][y+1]==1){
                    vector<int> v(2);
                    v[0]=x;
                    v[1]=y+1;
                    g[v[0]][v[1]]=2;
                    q.push(v);
                }
                if(y-1>=0&&g[x][y-1]==1){
                    vector<int> v(2);
                    v[0]=x;
                    v[1]=y-1;
                    g[v[0]][v[1]]=2;
                    q.push(v);
                }
            }
        }
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1) return -1;
            }
        }
        return res;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rotten;
        bool f=false;
        for(int i=0;i<grid.size();i++) 
            for(int j=0;j<grid[i].size();j++){
                if(
                    grid[i][j]==2
                    &&
                    ((i+1<grid.size()&&grid[i+1][j]==1)||
                    (i-1>=0&&grid[i-1][j]==1)||
                    (j+1<grid[0].size()&&grid[i][j+1]==1)||
                    (j-1>=0&&grid[i][j-1]==1))
                ){
                    vector<int> v(2);
                    v[0]=i;
                    v[1]=j;
                    rotten.push_back(v);
                }
                if(grid[i][j]==1)f=true;
            }
        if(!f) return 0;      
        if(!rotten.size()) return -1;
        int res=INT_MAX;
        res=bfs(rotten,grid);
        return res;
    }
};