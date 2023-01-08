// link: https://leetcode.com/problems/gas-station/

class Solution {
    bool possible(vector<int>& gas, vector<int>& cost,int pos){
        int i = pos ;
        int curr_gas = 0 ;
        do{
            curr_gas += gas[i] ;
            curr_gas -= cost[i] ;
            if(curr_gas < 0) return false ;
            ++i; 
            i %= cost.size() ;
        }while(i != pos);
        return true ;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)) return -1 ;
        vector<pair<int,int>> diff ;
        for(int i = 0 ; i < gas.size() ; i++) diff.push_back({gas[i] - cost[i] , i});
        sort(diff.begin(),diff.end(),[](const auto &a,const auto &b){
            return a.first > b.first ;
        });
        for(auto & x : diff){
            if(possible(gas,cost,x.second)) return x.second ;
        }
        return -1;
    }
};