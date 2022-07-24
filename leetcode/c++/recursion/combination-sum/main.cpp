// link : https://leetcode.com/problems/combination-sum/submissions/

class Solution {
    vector<vector<int>> s;
    void reccur(vector<int>&arr,int idx,int target,vector<int> &curr){
        if(target<0) return ;
        if(target==0){
            vector<int> temp(curr);
            s.push_back(temp);
            return ;
        }
        for(int i=idx;i<arr.size();i++){
            curr.push_back(arr[i]);
            if(arr[i]!=0)reccur(arr,i,target-arr[i],curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>curr;
        reccur(arr,0,target,curr);
        return s;
    }
};