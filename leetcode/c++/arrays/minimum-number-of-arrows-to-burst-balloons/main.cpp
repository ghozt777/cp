// link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int e = points[0][1] , curr = 0;
        int res = 0 ;
        while(curr < points.size()){
            while(curr < points.size() && points[curr][0] <= e){
                e = min(e,points[curr][1]);
                ++curr ;
            }
            ++res;
            if(curr != points.size()) e = points[curr][1];
        }
        return res ;
    }
};