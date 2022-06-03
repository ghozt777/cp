// link : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

/*
    Approach : greedy 
    it can easily be seen that any number (eg 8965 = 8 x 1000 + 9 x 100 + 6 x 10 + 5 x 1) can be expressed as a sum of powers of 10 i.e. deci-binary number
    In that case the minimum number of numbers required = max value of an individual digit as we need to add a power of 10 atleast that many times to express the number as a sum of power of 10
    So here is the code for that :
*/

class Solution {
public:
    int minPartitions(string n) {
        int res = -1 ;
        for(char x : n) if(x - '0' > res) res = x - '0' ;
        return res ;
    }
};