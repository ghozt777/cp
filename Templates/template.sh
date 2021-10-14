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
template="#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
int main(){

// solve()

    return 0;
}
"
touch ./A/a.cpp
touch ./B/a.cpp
touch ./C/a.cpp
echo "${template}" > ./A/a.cpp
echo "${template}" > ./B/a.cpp
echo "${template}" > ./C/a.cpp

subl .

