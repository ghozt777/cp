
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	// this queue os more of like a vector than a queue

	// the functions that are available are: 
	// push_front()
	// push_back()
	// pop_front()
	// pop_back()
	// size()
	// clear()
	// empty()
	// at()
	
	// It also provides iterators that are not availble with stacks , queues and priority_queues
	
	// Iterators:
	// begin , end , rbegin , rend
	// basically a dequeue is a doubly ended queue

	// hence the difference frim vectors is that in vecotrs only push back is allowed whereas in dequeue push back as well as push front is allowed


	deque<int> dq;
	cout << "the deque is: \n"; 
	dq.push_back(1);
	dq.push_back(5);
	dq.push_back(2);
	dq.push_front(1);
	dq.push_front(6);
	dq.push_front(4);
	dq.push_front(9);

	for(int i = 0 ; i < size(dq) ; i++)
		cout << dq.at(i) << " ";
	cout << "\npoping the first -> pop_front() and the last element -> pop_back() \n";
	dq.pop_front();
	dq.pop_back();
	cout << "\n Now the deque is: \n";
	for(int i = 0 ; i < size(dq) ; i++)
		cout << dq.at(i) << " ";

	return ;
}


