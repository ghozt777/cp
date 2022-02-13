/*
    ------------- SOLUTION IDEA ----------------------------------------------

    Stacks are used to store that such that the last data stored is at the top
    Or its a Last In First Out (LIFO) Data Structure

    How to Solve the problem :
    We use stack to store all the opening brackets i.e. '(' , '[' , '{'
    and if we encounter any closing bracket i.e. ')' , ']' , '}' we check it against the last opening backet if it matches then we continue else its not balanced
    We do this as in any expression the last opening bracket must be the one that closes first

    Also after the loop we need to check if there still are opening brackets or not if not then we can safely conclude that the expression is balanced
*/


/*
    -------------- QUESTION --------------------------------------------------------
    For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
    Example:
    Expression: (()())
    Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
    You need to return a boolean value indicating whether the expression is balanced or not.
    Note:
    The input expression will not contain spaces in between.
    Input Format:
    The first and the only line of input contains a string expression without any spaces in between.
    Output Format:
    The only line of output prints 'true' or 'false'.
    Note:
    You don't have to print anything explicitly. It has been taken care of. Just implement the function.
    Constraints:
    1 <= N <= 10^7
    Where N is the length of the expression.

    Sample Input 1 :
    (()()())
    Sample Output 1 :
    true

    Sample Input 2 :
    ()()(()
    Sample Output 2 :
    false
    
    Explanation to Sample Input 2:
    The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
*/


#include<bits/stdc++.h>
using namespace std;

bool validate(char bracket1, char bracket2){
    switch(bracket1){
    case '{':
    if(bracket2 == '}') return true;
    else return false;
    case '[':
    if(bracket2 == ']') return true;
    else return false;
    case '(':
    if(bracket2 == ')') return true;
    else return false;
    default:
    return true;
    }
    return true;
}

bool isBalanced(string expression)
{
    // Write your code here
    stack<char> check;
    for(char x : expression){
        if(x == '(' || x == '{' || x == '[') check.push(x);
        if(x == ')' || x == '}' || x == ']'){
            if(!check.empty() && validate(check.top(), x)) check.pop();
            else return false;
        }
    }
    return check.size() == 0;
}


int main(){
    cout << "Enter an expression: ";
    string expression;
    cin >> expression;
    isBalanced(expression) ? cout << "expression is balanced" : cout << "expression is not balanced";
    cout << endl;
    return 0;
}