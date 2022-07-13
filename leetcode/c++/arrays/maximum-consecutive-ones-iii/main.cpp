// link:https://leetcode.com/problems/max-consecutive-ones-iii/
// idea: Sliding Window

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n=nums.size();
        int res=INT_MIN;
        int l=0;
        int zero=0;
        for(int r=0;r<n;r++){
            zero+=nums[r]==0;
            if(zero>k) while(zero>k)zero-=nums[l++]==0;
            res=max(res,r-l+1);
        }
        return res;
    }
};