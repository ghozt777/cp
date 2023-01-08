#include<bits/stdc++.h>

using namespace std ;
using ll = long long ;
const ll INF = numeric_limits<ll>::max() ;

vector<ll> dijkstras(vector<vector<pair<ll,ll>>> &adj,ll s){
    set<ll> vis;
    vector<ll> dist(adj.size() , INF) ;

    dist[s] = 0 ;

    ll curr = 0 ;

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq ;
    pq.push({0,s}) ;

    while(vis.size() != adj.size()){

        ll curr = pq.top().second ;
        pq.pop() ;
        if(vis.find(curr) != vis.end()) continue ;
        vis.insert(curr) ;

        for(pair<ll,ll> n : adj[curr]){
            dist[n.second] = min(dist[n.second] , dist[curr] + n.first) ;
            pq.push({dist[n.second] , n.second}) ;
        }
    }

    return dist ;
}

void solve(){
    ll N , M ;
    cin >> N >> M ;
    vector<vector<pair<ll,ll>>> adj(N) ;
    for(ll i = 0 ; i < M ; i++){
        ll a , b , w ;
        cin >> a >> b >> w ;
        --a , --b ;
        adj[a].push_back({w,b}) ;
    }

    vector<ll> dist = dijkstras(adj,0) ;

    for(ll i = 0 ; i < dist.size() ; i++) cout << dist[i] << " " ;
    cout << endl ;
}

int main(){

    solve() ;

    return EXIT_SUCCESS ;
}