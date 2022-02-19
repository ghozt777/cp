// link : https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen ;
        for(int x : nums){
            if(seen.find(x) != seen.end()) return x ;
            else seen.insert(x) ;
        }
        return -1 ;
    }
};