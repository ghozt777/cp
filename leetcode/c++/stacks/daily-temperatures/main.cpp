// link : https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size()) ;
        stack<pair<int , int>> s ;
        for(int i = temperatures.size() - 1 ; i >= 0 ; --i){
            if(s.empty()) res[i] = 0 ;
            else{
                if(s.top().first > temperatures[i]) res[i] = s.top().second - i ;
                else{
                    while(s.top().first <= temperatures[i]){
                        s.pop() ;
                        if(s.empty()) break ;
                    }
                    res[i] = s.empty() ? 0 : s.top().second - i ;
                }
            }
            s.push(make_pair(temperatures[i] , i)) ;
        }
        return res ;
    }
};