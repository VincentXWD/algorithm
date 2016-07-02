#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int na = word1.length();
		int nb = word2.length();
		int dp[666][666];
		memset(dp, 0x7f7f7f7f, sizeof(dp));
		if(na == 0) return nb;
		if(nb == 0) return na;
		for(int i = 0; i <= na; i++) dp[i][0] = i;
		for(int i = 0; i <= nb; i++) dp[0][i] = i;
		for(int i = 1; i <= na; i++) {
			for(int j = 1; j <= nb; j++) {
				if(word1[i-1] == word2[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				else dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			}
		}
		return dp[na][nb];
	}
};

int main() {
	// freopen("in", "r", stdin);
	string a("ab");
	string b("bb");
	Solution c;
	cout << c.minDistance(a, b);
	return 0;
}