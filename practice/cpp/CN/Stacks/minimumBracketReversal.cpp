#include<bits/stdc++.h>
using namespace std;


/*
    QUESTION :

    Minimum bracket Reversal

    For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
    If the expression can't be balanced, return -1.
    Example:
    Expression: {{{{
    If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

    Expression: {{{
    In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
    Input Format :
    The first and the only line of input contains a string expression, without any spaces in between.
    Output Format :
    The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
    Note:
    You don't have to print anything. It has already been taken care of.
    Constraints:
    0 <= N <= 10^6
    Where N is the length of the expression.

    Time Limit: 1sec
    Sample Input 1:
    {{{
    Sample Output 1:
    -1

    Sample Input 2:
    {{{{}}
    Sample Output 2:
    1
*/

/*
    SOLTUION : 
    we first seperate the balanced part of the string expression by closing all the opening brackets
    and then process the unabalnced part to get the minimum number of reversals to make the unbalanced part balanced which is our answer

    if there are odd number of brackets we can never make then balanced so we return -1 ;

    CASE 1 : if we encounter a opening bracket eg : '{' -> we push it to the stack as we need to close it 
    CASE 2 : if we encounter a closing bracket eg: '}' -> read the subcases : 
        |
        ------> case a : If the stack is empty -> this closing bracket is a part of the unbalanced expression so we push it to the stack
        ------> case b : If the stack is not empty -> read the subcases 
                    |
                    --------> case I : the current char is a closing bracket and the stack is not empty , at the top of the stack there is a opening bracket '{' -> then we can close this opening bracket and mark it as balanced
                    --------> case II : the current char is a closing bracket and the stack is not empty , at the top of the stack there is a closing bracket '}' -> then the current bracket is a part of the unbalanced expression so we push it to the stack

    After the above code is executed the stack not contains the unbalanced expression 
    in the unbalanced expression we take two elements at a time and process then lets call them c1 and c2 
    if(c1 == c2) i.e. if both of them are opening brackets or closing brackets then we can flip on of them to make then balanced -> hence we increase the count by 1
    if(c1 != c2) i.e. they are something like '}' , '{' then we need to flip both of then so we increase the count by 2
    NOTE : '{', '}' this case is not possible as this is balanced and would've been caught by the above code ;
    At the end we return the computed count which is our answer                
*/


int countBracketReversals(string str) {
    // Write your code here
    if(str.size() % 2 == 1) return -1;
    stack<char> unbalanced;
    int count = 0;
    for(char x : str){
        switch(x){
        case '{':
        unbalanced.push(x);
        break;
        case '}':
        if(unbalanced.empty()) unbalanced.push(x);
        else if(unbalanced.top() == '{') unbalanced.pop();
        else unbalanced.push('}');
        break;
        default:
        break;
        }
    }
    while(!unbalanced.empty()){
        char c1 = unbalanced.top();
        unbalanced.pop();
        char c2 = unbalanced.top();
        unbalanced.pop();
        if(c1 == c2) count += 1;
        else count += 2;
    }
    return count;
}



int main(){
    string input;
    cin >> input;
    cout << countBracketReversals(input);
    return 0;
}
