// link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int n=matrix.size();
        const int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int res=0;
        for(int startCol=0;startCol<m;startCol++){
            for(int endCol=startCol;endCol<m;endCol++){
                map<int,int> m;
                int sum=0;
                m[0]=1;
                for(int row=0;row<n;row++){
                    sum+=matrix[row][endCol]-(startCol==0?0:matrix[row][startCol-1]);
                    res+=m[sum-target];
                    ++m[sum];
                }
            }
        }
        return res;
    }
};