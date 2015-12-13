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

const int maxn = 22;

int G[maxn][4];
bool vis[maxn];
int m, kase;
int ans[maxn];

template<int x> void init() {
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	kase = 0;
	if(x == 1) {
		memset(G, 0, sizeof(G));
	}
}

void dfs(int s, int cnt) {
	if(cnt > 20) {
		return;
	}
	if(cnt == 20) {
		if(G[s][1] == m || G[s][2] == m || G[s][3] == m) {
			printf("%d:  ", ++kase);
			for(int i = 0; i < 20; i++) {
				printf("%d ", ans[i]);
			}
			printf("%d\n", m);
		}
	}
	for(int i = 1; i <= 3; i++) {
		int cur = G[s][i];
		if(!vis[cur]) {
			vis[cur] = 1;
			ans[cnt] = cur;
			dfs(cur, cnt+1);
			vis[cur] = 0;
		}
	}
}

int main() {
	init<1>();
	for(int i = 1; i <= 20; i++) {
		scanf("%d %d %d", &G[i][1], &G[i][2], &G[i][3]);
	}
	while(~scanf("%d", &m) && m) {
		init<0>();
		vis[m] = 1;
		ans[0] = m;
		dfs(m, 1);
	}

	return 0;
}
