// link:https://leetcode.com/problems/course-schedule/

class Solution {
    vector<bool>vis;
    vector<bool> callStack;
    vector<vector<int>> adj;
    
    bool detectCycle(int s){
        if(!vis[s]){
            vis[s]=true;
            callStack[s]=true;
            bool res=false;
            for(int x:adj[s]){
                    if(callStack[x]) return true;
                    res=res||detectCycle(x);
                    if(res) return true;
            }
            callStack[s]=false;
            return res;
        }
        return false;
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses,false);
        callStack.resize(numCourses,false);
        adj.resize(numCourses);
        for(auto x:prerequisites){
            addEdge(x[1],x[0]);
        }
        for(int v=0;v<numCourses;v++){
            if(!vis[v]){
                if(detectCycle(v)) return false;
            }
        }
        return true;
    }
};