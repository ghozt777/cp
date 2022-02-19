// link : https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size() ;
        vector<int> temp(n) ;
        k %= n ;
        for(int i = 0 ; i < n ; i++) temp[(k + i) % n] = nums[i] ;
        for(int i = 0 ; i < n ; i++) nums[i] = temp[i] ;
    }
};