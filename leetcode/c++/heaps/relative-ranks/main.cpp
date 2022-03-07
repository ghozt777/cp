// link : https://leetcode.com/problems/relative-ranks/
class Solution {
public: 
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int , int>> pq ;
        for(int i = 0 ;  i < score.size() ; i++) pq.push(make_pair(score[i] , i)) ;
        vector<string> res(score.size()) ;
        int k = 1 ;
        while(!pq.empty()){
            int i = pq.top().second ;
            pq.pop() ;
            string pos ;
            if(k == 1) pos = "Gold Medal" ;
            else if(k == 2) pos = "Silver Medal" ;
            else if(k == 3) pos = "Bronze Medal" ;
            else pos = to_string(k) ;
            res[i] = pos ;
            ++k;
        }
        return res ;
    }
};