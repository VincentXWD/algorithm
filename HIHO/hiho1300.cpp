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

//kirai maxn
const int maxn = 1000010;
int n;
int st[maxn], top;
int dp[maxn];
char str[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%s", str)) {
		top = 0;
		n = strlen(str);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++) {
			if(str[i] == '(') st[top++] = i;
			else {
				if(top > 0) {
					int idx = st[--top];
					dp[i] = 1 + dp[idx-1];
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			printf("%d ", dp[i]);
			ans += dp[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}