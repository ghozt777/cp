
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


void Run();;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
  int stoneGameVII(vector<int>& S) {
        int N = S.size();
        vector<int> dp(N);
        for (int i = N - 2; ~i; i--) {
            int total = S[i];
            for (int j = i + 1; j < N; j++) {
                total += S[j];
                dp[j] = max(total - S[i] - dp[j], total - S[j] - dp[j-1]);
            }
        }
        cout << dp[N-1];
    }
}




