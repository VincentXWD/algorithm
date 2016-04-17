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

const int maxn = 555555;
int n;
int v[5555555];
int m;
int dp[maxn];

int main() {
	// freopen("in", "r", stdin);
	int vv, mm;
	while(~scanf("%d", &n) && n >= 0) {
		memset(dp, 0, sizeof(dp));
		memset(v, 0, sizeof(v));
		m = 1;
		int half = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &vv, &mm);
			half += vv * mm;
			while(mm--) v[m++] = vv;
		}
		for(int i = 1; i <= m; i++) {
			for(int j = half / 2; j >= v[i]; j--) {
				dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
			}
		}
		printf("%d %d\n", half-dp[half/2], dp[half/2]);
	}
	return 0;
}
