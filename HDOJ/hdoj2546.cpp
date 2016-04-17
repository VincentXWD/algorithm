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

//kirai
const int maxn = 1111;
int n, m;
int dp[maxn];
int w[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n) && n) {
		int maxx = -1;
		int pos;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
			if(maxx < w[i]) {
				maxx = w[i];
				pos = i;
			}
		}
		swap(w[pos], w[n]);
		scanf("%d", &m);
		if(m < 5) {
			printf("%d\n", m);
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i < n; i++) {
			for(int j = m - 5; j >= w[i]; j--) {
				dp[j] = max(dp[j], dp[j-w[i]]+w[i]);
			}
		}
		printf("%d\n", m - maxx - dp[m-5]);
	}
	return 0;
}