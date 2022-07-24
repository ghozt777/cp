// link: https://leetcode.com/problems/heaters/

class Solution {
    int findLeft(vector<int>&arr,int t){
        int res=-1;
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]<=t){
                res=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return res;
    }
    int findRight(vector<int>&arr,int t){
        int res=-1;
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>=t){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        vector<int> dist(houses.size(),INT_MAX);
        int curr=0;
        for(auto x:houses){
            int leftHeater=findLeft(heaters,x);
            int rightHeater=findRight(heaters,x);
            int distLeft=leftHeater==-1?INT_MAX:(x-heaters[leftHeater]);
            int distRight=rightHeater==-1?INT_MAX:(heaters[rightHeater]-x);
            dist[curr++]=min(distLeft,distRight);
        }
        int res=INT_MIN;
        for(int x:dist)res=max(res,x);
        return res;
    }
};