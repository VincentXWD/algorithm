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

typedef struct Node {
    int w;
    int s;
    int idx;
}Node;

const int maxn = 1111;
Node mice[maxn];
int n, ans;
int dp[maxn];
int pre[maxn];
int st[maxn];
int top;

bool cmp(Node a, Node b) {
	if(a.w == b.w) return a.s > b.s;
	return a.w < b.w;
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    n = 1;
    while(~scanf("%d %d", &mice[n].w, &mice[n].s)) {
        mice[n].idx = n;
        n++;
    }
    n--;
    sort(mice + 1, mice + n + 1, cmp);
    ans = 0;
    int pos;
    memset(dp, 0, sizeof(dp));
    memset(pre, -1, sizeof(pre));
    for(int i = 1; i <= n; i++) {
    	dp[i] = 1;
    	for(int j = 1; j < i; j++) {
    		if(dp[i] < dp[j] + 1 &&
    			mice[i].s < mice[j].s &&
    			mice[i].w > mice[j].w) {
    			dp[i] = dp[j] + 1;
    			pre[mice[i].idx] = mice[j].idx;
    		}
    	}
    	if(ans < dp[i]) {
    		ans = dp[i];
    		pos = mice[i].idx;
    	}
    }
    top = 0;
    for(int i = pos; ~i; i=pre[i]) st[top++] = i;
    printf("%d\n", ans);
    while(top) printf("%d\n", st[--top]);
    return 0;
}