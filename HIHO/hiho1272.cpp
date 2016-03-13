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

const int maxn = 55;
int n;
float a[maxn];
int b[maxn];
bool vis[maxn];
int ans;

int flag;
void dfs(int cnt, float cura, int curb) {
	if(cnt <= 3) {
		if(cura == (int)cura && (int)cura % 5 == 0) {
			ans = max(ans, curb);
		}
		if(cnt == 3) return;
	}
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			dfs(cnt+1, cura+a[i], curb+b[i]);
			vis[i] = 0;
		}
	}
}
int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%f %d", &a[i], &b[i]);
		}
		memset(vis, 0, sizeof(vis));
		ans = -1;
		flag = 0;
		dfs(0, 0.0, 0);
		printf("%d\n", ans);
	}
	return 0;
}