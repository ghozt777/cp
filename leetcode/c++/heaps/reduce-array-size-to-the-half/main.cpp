// link : https://leetcode.com/problems/reduce-array-size-to-the-half/

// IDEA: Remove the least number of elements to reduce the size of the array to half its initial size
// ALGO : Greedy

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int , int> hm ;
        priority_queue<int> pq ;
        int res = 0 ;
        int half = arr.size()/2 ;
        for(int x : arr) hm[x]++ ;
        for(auto x : hm) pq.push(x.second) ;
        while(half > 0){
            half -= pq.top() ;
            pq.pop() ;
            ++res ;
        }
        return res ;
    }
};