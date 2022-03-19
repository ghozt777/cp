// link: https://leetcode.com/problems/4sum/
// algo used : two pointers use find a second targetSum 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res ;
        if(nums.empty()) return res ;
        sort(nums.begin() , nums.end()) ;
        const int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n; j++){
                int target2 = target - nums[i] - nums[j] ;
                int start = j + 1 ;
                int end = n - 1 ;
                while(start < end){
                    int sum = nums[start] + nums[end] ;
                    if(sum == target2){
                        vector<int> ans(4) ;
                        ans[0] = nums[i] ;
                        ans[1] = nums[j] ;
                        ans[2] = nums[start] ;
                        ans[3] = nums[end] ;
                        res.push_back(ans);
                        ++start ; --end ;
                        while(start < end && nums[start] == ans[2]) ++start ;
                        while(end > start && nums[end] == ans[3]) --end ;
                    }
                    else if(sum > target2) --end ;
                    else ++start ;
                }
                while(j + 1 < n && nums[j] == nums[j + 1]) ++j ;
            }
             while(i + 1 < n && nums[i] == nums[i + 1]) ++i ;
        }
        return res ;
    }
};