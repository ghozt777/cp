// link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dfs(int s){
        int res=0;
        vis[s]=true;
        for(int x:adj[s]) if(!vis[x]) res+=dfs(x);
        return 1+res;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n,false);
        for(auto x:edges) addEdge(x[0],x[1]);
        long res = 0, sum = n;
        for(int v=0;v<n;v++) if(!vis[v]){
            int curr=dfs(v) ;
            sum-=curr;
            res+=curr*sum;
        }
        return res;
    }
};