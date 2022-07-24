// link : https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](const vector<int>&a,const vector<int>&b){
            return a[0]==b[0]?a[1]<b[1] : a[0]>b[0];
        });
        vector<vector<int>> res;
        for(auto x:people){
            res.insert(res.begin()+x[1],x);
        }
        return res;
    }
};