// link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
    bool check(vector<int>&weights,int days,int w){
        int curr=0;
        int i=0;
        const int n=weights.size();
        while(i<n&&days){
            if(curr+weights[i]<=w){
                curr+=weights[i];
                ++i;
            }
            else{
                --days;
                curr=0;
            }
        }
        return i==n;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=INT_MAX,end=0;
        for(int i=0;i<weights.size();i++){
            start=min(start,weights[i]);
            end+=weights[i];
        }
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(weights,days,mid)){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
};