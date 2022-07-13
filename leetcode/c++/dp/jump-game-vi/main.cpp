/*

// Top Down : TLE
using ll=long long;
const ll INF=LLONG_MAX;
class Solution {
    vector<ll>dp;
    ll solve(vector<int>&nums,int k,int curr){
        if(curr==0) return dp[curr]=nums[0];
        if(dp[curr]!=INF) return dp[curr];
        ll res=INT_MIN;
        for(int i=1;i<=k;i++){
            if(curr-i>=0)res=max(res,nums[curr]+solve(nums,k,curr-i));
        }
        return dp[curr]=res;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        dp.resize(nums.size()+1,INF);
        return solve(nums,k,nums.size()-1);
    }
};

// Bottom Up ; TLE
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<long>dp(n+1,INT_MIN);
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(i-j>=0) dp[i]=max(dp[i],(long)nums[i-1]+dp[i-j]);
                else break;
            }
        }
        return dp[n];
    }
};

*/

// Optimized DP
class Solution{
    public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(size(nums), INT_MIN);
        multiset<int> s ({ dp[0] = nums[0] });         // set dp[0] = nums[0] and insert it into set
        for(int i = 1; i < size(nums); i++) {
            if(i > k) s.erase(s.find(dp[i - k - 1]));  // erase elements from which we cant jump to current index
            s.insert(dp[i] = *rbegin(s) + nums[i]);    // choose element with max score and jump from that to the current index
        }
        return dp.back();
    }
};