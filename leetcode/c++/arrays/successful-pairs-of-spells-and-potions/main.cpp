// link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
    int bs(vector<int>&potions,long long curr, long long success){
        int res=-1;
        int start=0;
        int end=potions.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long x=potions[mid];
            long long p=curr*x;
            if(p<success){
                start=mid+1;
            }
            else{
                res=mid;
                end=mid-1;
            }
        }
        return res;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(),potions.end());
        const int n=potions.size();
        for(int x:spells){
            int idx=bs(potions,x,success);
            res.push_back(idx==-1?0:(n-idx));
        }
        return res;
    }
};