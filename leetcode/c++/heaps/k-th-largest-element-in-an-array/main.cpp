// link : https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq ; // default queue in c++ == max heap for min heap use priority_queue<int , vector<int> , greater<int>> pq ;
        for(int x : nums) pq.push(x) ;
        int c = 0 ;
        while(c++ != k - 1) pq.pop();
        return pq.top() ;
    }
};