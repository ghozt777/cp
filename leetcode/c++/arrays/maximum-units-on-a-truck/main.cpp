// link: https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
           return a[1]>b[1]; 
        });
        int res=0;
        int curr=0;
        while(curr<boxTypes.size()&&truckSize>0){
            res+=min(truckSize,boxTypes[curr][0])*boxTypes[curr][1];
            truckSize-=min(truckSize,boxTypes[curr][0]);
            ++curr;
        }
        return res;
    }
};