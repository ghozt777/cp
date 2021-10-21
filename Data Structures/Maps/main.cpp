#include<bits/stdc++.h>
using namespace std;
typedef map<string , int> msi;
#define IN emplace

void Run();

int main() {
	Run();
	return 0;
}

void Run() {
	// maps are basically dictionaries
	// a map also stores everuthing in a sorted order
	// the sorting is done based on the keys
	// redundant keys are overriden
	msi m;
	m["foo"] = 69;
	m.IN("ghozt" , 96); //this is simliar to m["ghozt"] = 96;
	// there are a couple of functions that we can implement in maps
	// but first lets print the map
	// internally it stores a pair of string and integer than can be accessed using .first and .second
	for(pair<string , int> x : m)
		cout << "(key)🔑: " << x.first << " || (value)🍕: " << x.second << "\n";
	// intentionally creating a reduntant value for a key
	m.IN("foo" , 78);
	m.IN("foo" , 56);
	m.IN("foo" , 12); // this one (the last one) overrides the prev values as a key can only be assisiated with one unique value
	// to count the number of occurences of a key (if present == 1 as it is always unique)
	// therefore .count(key) can either return 1 or 0
	cout << "\nghozt occurs : " << m.count("ghozt") << " times";
	cout << "\n Foo occurs: " << m.count("Foo") << " times";
	m.IN("fooo" , 15);
	m.IN("mooo" , 13);
	m.IN("cooo" , 16);
	m.IN("dooo" , 25);
	m.IN("pooo" , 75);
	cout << "\nadding in some new elements: ";
	for(auto x : m)
		cout << "(key)🔑: " << x.first << " || (value)🍕: " << x.second << "\n";
	cout << "\nprinting the elements in the map using iterators: ";
	// printing the dictionary using iterators:
	for(auto x = m.begin() ; x != m.end() ; x++)
		cout << "(key)🔑: " << x->first << " || (value)🍕: " << x->second << "\n";
	// to find a particular element using the key
	cout << "\nvalue for gooo is " << (m.find("gooo"))->second;
	cout << "\nvalue for mooo is " << (m.find("mooo"))->second;
	// erasing some elements
	m.erase(m.begin());
	msi::iterator itr;
	itr = m.begin();
	itr++;
	itr++;
	m.erase(m.begin() , itr);
	cout << "\nnow the map is : ";
	for(pair<string , int> x : m)
		cout << "(key)🔑: " << x.first << " || (value)🍕: " << x.second << "\n";
	// to check if the map is empty
	cout << "\nquestion : is the map currently empty ?  ans : " ;
	if(m.empty()) cout << "true";
	else cout << "false";
	cout << "\nexpliiclity clearing the map";
	m.clear();
	cout << "\nquestion : is the map currently empty ?  ans : " ;
	if(m.empty()) cout << "true";
	else cout << "false";

	/*
	Note : There is also an unordered_map that has O(1) operations in almost all cases and O(n) as the worst case where n = size of the map
	*/

	// creating a multi map 
	// a multi map allows redundant values assosiated with a particular key without overriding the previous one

	multimap<string , int> mulmap;
	mulmap.IN("ghozt" , 96);
	mulmap.IN("ghozt" , 69);

	cout << "\nprinting a multimap: ";

	for(pair<string , int> x : mulmap){
		cout << "key: " << x.first << " value: " << x.second << "\n";	
	}

	cout << "number of values of \"ghozt\" : " << mulmap.count("ghozt");
	
	return ;
}

















