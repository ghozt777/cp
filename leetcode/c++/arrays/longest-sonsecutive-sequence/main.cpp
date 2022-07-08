//link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public: // 0 1 1 2
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int res=1;
        int curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                ++curr;
                res=max(res,curr);
            }
            else if(nums[i]==nums[i-1]){
                int j=i;
                while(j<nums.size()&&nums[j]==nums[i])++j;
                i=j;
                --i;
            }
            else curr=1;
        }
        return res;
    }
};