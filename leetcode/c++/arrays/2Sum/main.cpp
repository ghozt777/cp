// link : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,-1) ;
        unordered_map<int , int> ht ;
        for(int i = 0 ; i < nums.size() ; i++){
            unordered_map<int , int>::iterator it = ht.find(target - nums[i]) ; 
            if(it != ht.end()){
                ans[0] = it->second ;
                ans[1] = i ;
                return ans ;
            }
            else ht.insert(make_pair(nums[i] , i)) ;
        }
        return ans ;
    }
};