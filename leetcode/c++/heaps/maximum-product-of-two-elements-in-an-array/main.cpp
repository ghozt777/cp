// link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq ;
        for(int x : nums) pq.push(x) ;
        int ans = 1 ;
        for(int i = 0 ; i < 2 ; i ++){
            ans *= (pq.top() - 1) ;
            pq.pop() ;
        }
        return ans ;
    }
};