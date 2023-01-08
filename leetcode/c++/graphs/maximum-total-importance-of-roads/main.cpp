// link: https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
    using ll = long long ;
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> degree(n,0) ;
        for(auto r : roads){
            ++degree[r[0]];
            ++degree[r[1]];
        }

        vector<vector<ll>> s ;
        for(ll i = 0 ; i < n ; i++){
            s.push_back({degree[i],i});
        }

        sort(s.begin(),s.end()) ;

        vector<ll> score(n,0);

        ll curr = 1 ;
        for(auto x : s){
            score[x[1]] = curr++ ;
        }

        ll res = 0 ;
        for(auto r : roads){
            res += (score[r[0]] + score[r[1]]);
        } 

        return res ;
    }
};