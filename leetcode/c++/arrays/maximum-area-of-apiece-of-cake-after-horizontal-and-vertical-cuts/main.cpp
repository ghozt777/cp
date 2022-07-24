// link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
    const int MOD=pow(10,9)+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long mh=max(horizontalCuts[0],h-horizontalCuts[horizontalCuts.size()-1]);
        for(int i=1;i<horizontalCuts.size();i++) mh=max(mh,(long long)horizontalCuts[i]-horizontalCuts[i-1]);
        long long mw=max(verticalCuts[0],w-verticalCuts[verticalCuts.size()-1]);
        for(int i=1;i<verticalCuts.size();i++) mw=max(mw,(long long)verticalCuts[i]-verticalCuts[i-1]);
        long long res=(mh%MOD)*(mw%MOD);
        res=res%MOD;
        return (int)res;
    }
};