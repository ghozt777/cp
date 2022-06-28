// link: https://leetcode.com/problems/next-permutation/
// video explaination: https://www.youtube.com/watch?v=6qXO72FkqwM

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int n=nums.size();
        int peak=n-1;
        while(peak>0&&nums[peak]<=nums[peak-1]) --peak;
        if(peak==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int toSwap=peak-1;
        int bestCandidate=peak;
        for(int i=peak;i<n;i++){
            if(nums[i]>nums[toSwap]&&nums[i]<nums[bestCandidate]) bestCandidate=i;
        }
        swap(nums[toSwap],nums[bestCandidate]);
        sort(nums.begin()+peak,nums.end());
    }
};