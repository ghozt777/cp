#include<bits/stdc++.h>
using namespace std;

void Run();

int main() {
	Run();
	return 0;
}

void Run() {
	// internally implemented as a stack or a linked list 
	// a stack is a last in first out or (LIFO) Data Structure
	stack<int> st;
	// top functions to learn :
	// pop()
	// push() or emplace()
	// top()
	// size()
	// empty()
	for(int i = 10 ; i >= 1 ; i--)
		st.emplace(i);
	while(!st.empty()){
		cout << st.top() << "\n";
		st.pop();
	}
	// cout << st.top(); this will throw a segmentation fault error
}