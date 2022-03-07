// link : https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
    string getString(char x){
        string s(1, x);
        return s;  
    }
public:
    string frequencySort(string s) {
        unordered_map<char , int> hm ;
        priority_queue<pair<int , char>> pq;
        for(char x : s) hm[x]++ ;
        for(auto x : hm) pq.push(make_pair(x.second , x.first)) ;
        string res = "" ;
        while(!pq.empty()){
            pair<int , char> top = pq.top() ;
            pq.pop() ;
            char x = top.second ;
            for(int i = 0 ; i < top.first ; i++) res.append(getString(x)) ;
        }
        return res ;
    }
};