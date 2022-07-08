// link: https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),[](const int&a, const int&b){
            return a>b;
        });
        int res=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>i)++res;
            else break;
        }
        return res;
    }
};