// link: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> seq;
        for(int i=0;i<intervals.size();){
            if(i==0){
                seq.push_back({intervals[i][0],intervals[i][1]});
                ++i;
            }
            else{
                int check=intervals[i-1][0];
                if(intervals[i][0]!=check){
                    seq.push_back({intervals[i][0],intervals[i][1]});
                    ++i;
                }
                else{
                    int curr=i;
                    while(curr<intervals.size()&&intervals[curr][0]==intervals[i][0])++curr;
                    i=curr;
                }
            }
        }
        int res=intervals.size()-seq.size();
        // cout<<res<<endl;
        // for(auto x:seq){
        //     cout<<"("<<x.first<<","<<x.second<<")\n";
        // }
        int last=seq[0].second;
        for(int i=1;i<seq.size();i++){
            if(seq[i].first<last){
                ++res;
                last=min(last,seq[i].second);
            }
            else last=seq[i].second;
        }
        return res;
    }
};