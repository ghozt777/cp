// link: https://leetcode.com/problems/max-points-on-a-line/
// Idea From : https://leetcode.com/problems/max-points-on-a-line/solutions/47117/sharing-my-simple-solution-with-explanation/?orderBy=most_votes
/*

First, let's talk about mathematics.

How to determine if three points are on the same line?

The answer is to see if slopes of arbitrary two pairs are the same.

Second, let's see what the minimum time complexity can be.

Definitely, O(n^2). It's because you have to calculate all slopes between any two points.

Then let's go back to the solution of this problem.

In order to make this discussion simpler, let's pick a random point A as an example.

Given point A, we need to calculate all slopes between A and other points. There will be three cases:

Some other point is the same as point A.

Some other point has the same x coordinate as point A, which will result to a positive infinite slope.

General case. We can calculate slope.

We can store all slopes in a hash table. And we find which slope shows up mostly. Then add the number of same points to it. Then we know the maximum number of points on the same line for point A.

We can do the same thing to point B, point C...

Finally, just return the maximum result among point A, point B, point C... 
 
*/

class Solution {
    using DD = double ;
    const DD INF = numeric_limits<DD>::max() ;
public:
    int maxPoints(vector<vector<int>>& points) {

        const int N = points.size() ;
        int res = 0 ;

        for(int i = 0 ; i < N ; i++){

            map<DD,int> count ;
            int same_point = 1 ;

            for(int j = i + 1 ; j < N ; j++){
                int x1 = points[i][0] , x2 = points[j][0] , y1 = points[i][1] , y2 = points[j][1] ;
                if(x1 == x2 && y1 == y2) ++ same_point ;
                else{
                    DD m = x1 == x2 ? INF : DD(y2 - y1) / DD(x2 - x1); 
                    ++count[m] ;
                }
            }

            int local_res = 0 ;

            for(auto & x : count) local_res = max(local_res,x.second) ;

            local_res += same_point ;

            res = max(res,local_res) ;
        }
        return res ;
    }
};