#include<bits/stdc++.h>
using namespace std;

#define PQ priority_queue

void Run();

int main() {
	Run();
	return 0;
}

void Run() {
	// this is a First In First Out or (FIFO) Data Structure
	// the functions are: 
	// push () or emplace()
	// pop()
	// front()
	// size()
	// empty()
	// Note : there are no iterators in stack and queue
	queue<int> q;
	for(int i = 10 ; i >= 1 ; i--)
		q.emplace(i);
	while(!q.empty())
	{ cout << q.front() << "\n" ; q.pop(); }

	// VVI : This Data Structure is very important for CP
	// priority_queue
	// this stores all the elements in sorted fashion and the Time Complexity for Operations is O(log(n))
	priority_queue<int> pq;
	// uses heapy (heap sort) to sort the elements
	// a priority_queue contains all the elements in descending odrder
	// Eg:
	cout << "\ncreating a priority queue: \n";
	pq.emplace(1);
	pq.emplace(5);
	pq.emplace(2); 
	pq.emplace(3);
	pq.emplace(9);
	pq.emplace(1);
	while(!pq.empty()){
		cout << "\t" << pq.top() << "\n";
		pq.pop();
	}
	// therefore the maximum element is at the top then the second max then the tird max and so on...

	// for a priority queue of a pair it sorts as per the first element and if the first elements are equal it sorts on the basis of the second element
	// Eg:
	priority_queue<pair<int , int>> pqi;
	pqi.emplace(2,1);
	pqi.emplace(1,1); // last
	pqi.emplace(1,3);
	pqi.emplace(1,2);
	pqi.emplace(2,9); // first

	cout << "\npriority queue of pair\n";

	while(!pqi.empty()){
		cout << "first : " << pqi.top().first << " second: " << pqi.top().second << "\n";
		pqi.pop();
	}
	// to explicity create a inimum priority queue without using the provided one

	priority_queue<int> mp;
	// taking the above code as an example: 
	// Trick : Just Negate the elements and while fetching them negate then again to get the original one back
	mp.emplace(-1);
	mp.emplace(-5);
	mp.emplace(-2);
	mp.emplace(-3);
	mp.emplace(-9);
	mp.emplace(-1);

	cout << "\nexplicit minimum priority queue: \n";
	while(!mp.empty()){
		cout << "\t" << -1 * mp.top() << "\n";
		mp.pop();
	}

	// to create a minimum priority queue use:
	cout << "\nCreating a minimum priority queue: \n";
	priority_queue<int , vector<int> , greater<int>> mpq;

	mpq.emplace(1); // first
	mpq.emplace(5);
	mpq.emplace(2); 
	mpq.emplace(3);
	mpq.emplace(9); // last
	mpq.emplace(1);

	while(!mpq.empty()){
		cout << "\t" << mpq.top() << "\n";
		mpq.pop();
	}
}

















