// link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k>=cardPoints.size()) return accumulate(cardPoints.begin(),cardPoints.end(),0);
        const int n=cardPoints.size();
        vector<int> prefix(k,0);
        vector<int> suffix(k,0);
        for(int i=0;i<k;i++){
            if(i==0){
                prefix[i]=cardPoints[i];
                suffix[i]=cardPoints[n-i-1];
            }
            else{
                prefix[i]=cardPoints[i]+prefix[i-1];
                suffix[i]=cardPoints[n-1-i]+suffix[i-1];
            }
        }
        // bruteforce the solution by dividing the result into 2 parts one from left and one from right end of the array
        int res=0;
        for(int i=0;i<=k;i++){
            int left=i;
            int right=k-left;
            int leftSum=left==0?0:prefix[left-1];
            int rightSum=right==0?0:suffix[right-1];
            res=max(res,leftSum+rightSum);
        }
        return res;
    }
};