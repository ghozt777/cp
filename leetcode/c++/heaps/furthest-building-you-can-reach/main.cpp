// link : https://leetcode.com/problems/furthest-building-you-can-reach/

/*
    *Explanation && Idea:
    
    *Some observations:

    with ladder we can cover any height . So will Prefer ladder to cover large difference.
    If next building height is greater than only we need brick or ladder to cross it , if next building height if less than current building we can directly jump.
    *Algorithm:
    *Go greedly

    First use all the ladders whenever we have to go to higher building and also add the difference b/w height in min_heap.
    if min_heap.size()==ladders it means we have used all the ladders.
    now let say after all ladders are used and we we found a larger building , add difference to min_heap and use bricks at a place where height difference is minimum by replacing the ladder from that place.
    If idea is clear to you try to code yourself then see my implementation for above though process
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq ;
        for(int i=0;i<heights.size()-1;i++){
            int diff=heights[i+1]-heights[i];
            if(diff>0) pq.push(diff);
            if(pq.size()>ladders) bricks -= pq.top() , pq.pop() ;
            if(bricks<0) return i;
        }
        return heights.size()-1;
    }
};