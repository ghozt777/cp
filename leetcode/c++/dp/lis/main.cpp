// link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size());
        lis[0]=1;
        for(int i=1;i<nums.size();i++){
            lis[i]=1;
            for(int j=i;j>=0;j--){
                if(nums[j]<nums[i])lis[i]=max(lis[i],1+lis[j]);
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};