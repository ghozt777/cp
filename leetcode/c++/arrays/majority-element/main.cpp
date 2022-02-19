// link : https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> freq ;
        for(int x : nums) freq[x]++ ;
        for(auto x : freq) if(x.second > nums.size() / 2) return x.first ;
        return 0 ;
    }
};