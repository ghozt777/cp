class Solution {
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& adj,int node,vector<int>&curr){
        curr.push_back(node);
        if(node == adj.size() - 1){
            res.push_back(curr);
            curr.pop_back();
            return ;
        }
        for(int x : adj[node]){
            dfs(adj,x,curr);
        }
        curr.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> buff ;
        dfs(graph,0,buff);
        return res ;
    }
};