// link : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> seen ;
        for(int x : nums) seen.insert(x) ;
        vector<int> res ;
        for(int i = 1 ; i <= nums.size() ; i++) if(seen.find(i) == seen.end()) res.push_back(i) ;
        return res ;
    }
};