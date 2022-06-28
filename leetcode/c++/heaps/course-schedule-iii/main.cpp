// link : https://leetcode.com/problems/course-schedule-iii/
/*
    Time Complexity : O(N*log(N)) , Space Complexity : O(N)
    
    Explaination

    It may first seem that it can be done by dynamic programming. In this approach we can create all possible subsequences of the courses and return the maximum length of the courses. But in this case we will not consider the order of the courses which is very important to maximise the courses done. So this approach will not work. So we have to take other approach. Here is the approach which worked for me :

    Approach :

    The main concept here is doing the courses first whose deadline is shorter and if you cant do that course before deadline see if you can minimise the total time taken by replacing the previous longest course with the current course as any previous couse had smaller deadline than current.

    So what we can do is the following :

    At first sort the courses in increasing order of their deadline/lastday. So that the courses with shorter deadlines are done before others. Also declare a priority queue for storing the length of the courses done. Along with that declare a variable which stores the total time taken till now.

    Iterating over the arrayif the sum of current course dutration and the previous total durartion is less than lastday of that course then we can do that course. So add its duration to total duration and add it to the priority queue.

    If the previous condition is not met we cant do the course. So we can try to minimise the total time taken so that we can make more room for new course in future. So if any course is done before (we can check that be checking the priority queu is empty or not) we check if it is the longest course till now, if its not then replace the previous longest course with current course. For this remove the top course time from queue and total time and add current course time to both. This replace will work every time as the current lastday is always less than any of previous lastday.

    If a course doesnt fullfill any condition then skip it (As you can't do it any way).

    At last the priority queue will only contain the courses which were done. So total number of courses is the size of the queue which is returned.

    Note : The comp function compares the lastday of each course for sorting.


*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(), [](vector<int>&a,vector<int>&b){ return a[1] < b[1]; });
        priority_queue<int> pq ;
        int startTime=0;
        for(auto x:courses){
            if(startTime+x[0]<=x[1]){
                startTime+=x[0];
                pq.push(x[0]);
            }
            else if(!pq.empty() && pq.top()>x[0]){
                startTime-=pq.top();
                pq.pop();
                startTime+=x[0];
                pq.push(x[0]);
            }
        }
        return pq.size();
    }
};