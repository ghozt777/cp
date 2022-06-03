// NO TLE : AC
// link : https://leetcode.com/problems/count-number-of-teams/
// Combinatorics

class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int n = rating.size() ;
        int total_teams = 0 ;
        for(int i = 1 ; i < n - 1 ; i++){
            int leftSmaller = 0 ; 
            int rightGreater = 0 ;
            int leftGreater = 0 ;
            int rightSmaller = 0 ;
            for(int k = i - 1 ; k >= 0 ; k--){
                if(rating[k] > rating[i]) ++leftGreater ;
                if(rating[k] < rating[i]) ++leftSmaller ;
            }
            for(int k = i + 1 ; k < n ; k++){
                if(rating[k] > rating[i]) ++rightGreater ;
                if(rating[k] < rating[i]) ++rightSmaller ;
            }
            total_teams += (leftSmaller * rightGreater) + (leftGreater * rightSmaller) ;
        }
        return total_teams ;
    }
};