// link : https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/

// this solution uses Bellman Ford Algorithm
// just note that for mac number of k stops in between flights there can be a maximum number of (k + 1) flights

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using vi = vector<int> ;
        const int INF = INT_MAX ;
        vi dist(n , INF) ;
        dist[src] = 0 ;
        for(int c = 0 ; c < k + 1 ; c++){
            vi temp(dist) ;
            for(auto flight : flights){
                int u = flight[0] ;
                int v = flight[1] ;
                int w = flight[2] ;
                if(dist[u] != INF) temp[v] = min(temp[v] , dist[u] + w) ;
            }
            dist = temp ;
        }
        return dist[dst] == INF ? -1 : dist[dst] ;
    }
};