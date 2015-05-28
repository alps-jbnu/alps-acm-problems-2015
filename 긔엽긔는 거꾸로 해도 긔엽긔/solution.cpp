#include <iostream>
#include <memory.h>
using namespace std;

#define min(a,b) (a<b?a:b)

int dp[5050][5050];

int makePaline(string const& p, int l, int r){
	if (dp[l][r] > -1) return dp[l][r];
	if (l >= r) return 0;
	if (p[l] == p[r]) return (dp[l][r] = makePaline(p, l+1, r-1));
	return (dp[l][r] = 1 + min(makePaline(p, l+1, r), makePaline(p, l, r-1)));
}

int main(){
	memset(dp, -1, sizeof(dp));
	string s;
	cin >> s;
	cout<< makePaline(s, 0, s.length()-1);
	return 0;
}
