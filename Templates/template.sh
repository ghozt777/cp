#!/bin/bash
echo -n "Round Name:"
read round
if [$round == ""]
then 
	echo "can't create an empty directory :( "
	exit 0
fi
mkdir $round
cd $round
mkdir A
mkdir B
mkdir C
template="
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


	return ;
}

"
touch ./A/a.cpp
touch ./A/input.txt
touch ./A/output.txt
touch ./B/a.cpp
touch ./B/input.txt
touch ./B/output.txt
touch ./C/a.cpp
touch ./C/input.txt
touch ./C/output.txt 
echo "${template}" > ./A/a.cpp
echo "${template}" > ./B/a.cpp
echo "${template}" > ./C/a.cpp

subl .

