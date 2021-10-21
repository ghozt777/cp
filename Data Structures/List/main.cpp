
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

	// the functions that are available are: 
	// push_front()
	// push_back()
	// pop_front()
	// pop_back()
	// size()
	// clear()
	// empty()
	// at()
	// remove() -> Time Complexity: O(1)

	list<int> li;

	li.push_front(1);
	li.push_front(9);
	li.push_front(4);
	cout << "\n The List Contains:\n";
	for(auto x = li.begin()  ; x != li.end() ; x++)
		cout << *x << " ";

	cout << "\nRemoving elements takes constat time or O(1): Removing 1 we get\n";
	li.remove(1);
	for(list<int>::iterator x = li.begin()  ; x != li.end() ; x++)
		cout << *x << " ";

	return ;
}


