// This will result in a TLE !! 
// link : https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>> > adj(n) ;
        for(auto & a : flights) adj[a[0]].push_back(make_pair(a[1] , a[2])) ;
        queue<pair<int , int>> toProcess ;
        toProcess.push(make_pair(src , 0)) ;
        int res = INT_MAX ;
        while(!toProcess.empty() && k-- >= 0){
            int n = toProcess.size() ;
            for(int i = 0 ; i < n ; i++){
                auto curr = toProcess.front() ;
                toProcess.pop() ;
                for(auto x : adj[curr.first]){
                    if(res > (x.second + curr.second)){
                        toProcess.push(make_pair(x.first , curr.second + x.second)) ;
                        if(x.first == dst) res = min(res , x.second + curr.second) ;
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res ;
    }
};