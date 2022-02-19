// link : https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0 ;
        while(i < nums.size()){
            if(nums[i] == 0){
                int curr = i ;
                while(curr < nums.size() && nums[curr] == 0) ++curr ;
                if(curr < nums.size())swap(nums[curr] , nums[i]) ;
            }
            ++i ;
        }
    }
};