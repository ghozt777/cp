class Solution {
    int helper(vector<int> &curr , vector<int> &arr , int n){
        if(n == 0) return curr.size() ; 
        int res = INT_MIN ;
        if(!curr.size() || arr[n - 1] < curr[curr.size() - 1]){
            curr.push_back(arr[n - 1]) ;
            int res2 = helper(curr , arr , n - 1) ;
            curr.pop_back() ;
            int res1 = helper(curr , arr , n - 1) ;
            res = max(res , max(res1 , res2)) ;
        }
        else res = max(res , helper(curr , arr , n - 1)) ;
        return res ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> curr ;
        return helper(curr , nums , nums.size()) ;
    }
};