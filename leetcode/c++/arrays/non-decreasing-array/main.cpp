// link : https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        const int n=arr.size();
        bool changed=false;
        for(int i=0;i<n-1;i++){
            if(arr[i]<=arr[i+1]) continue;
            if(changed) return false;
            if(i==0||arr[i+1]>=arr[i-1]) arr[i]=arr[i+1]; // decrease the left element => (greedy)
            else arr[i+1]=arr[i]; // increase the right element => (not a greedy approach but there is no other option)
            changed=true;
        }
        return true;
    }
};