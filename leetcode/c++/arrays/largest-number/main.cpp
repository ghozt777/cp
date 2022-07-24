// link: https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int&a,const int&b){
            string stra=to_string(a) ;
            string strb=to_string(b) ;
            return (stra+strb)>(strb+stra);
        });
        string res="";
        if(nums[0]==0) return "0";
        for(int x:nums) res+=to_string(x) ;
        return res;
    }
};