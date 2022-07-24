// link: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int x:nums)++m[x];
        const int n=nums.size();
        vector<int> res;
        for(auto x:m){
            if(x.second>n/3)res.push_back(x.first);
        }
        return res;
    }
};