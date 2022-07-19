// link: https://leetcode.com/problems/find-right-interval/

class Solution {
    int bs(vector<int>&arr,int target){
        int start=0;
        int end=arr.size()-1;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]<target)start=mid+1;
            else{
                res=mid;
                end=mid-1;
            }
        }
        return res;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        vector<int> arr;
        map<int,int>m;
        for(int i=0;i<A.size();i++){
            m[A[i][0]]=i;
            arr.push_back(A[i][0]);
        }
        sort(arr.begin(),arr.end());
        vector<int>res;
        for(auto x:A){
            int idx=bs(arr,x[1]);
            res.push_back(idx==-1?-1:m[arr[idx]]);
        }
        return res;
    }
};