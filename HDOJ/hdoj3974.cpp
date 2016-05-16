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

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

#define lrt rt << 1
#define rrt rt << 1 | 1
const int maxn = 50010;
int n, m;
int in[maxn];
int depth[maxn];
bool vis[maxn];
vector<int> G[maxn];
int q[maxn], front, tail;
int task[maxn];

void bfs(int rt) {
	front = tail = 0;
	int lv = 0;
	depth[rt] = lv++; q[tail++] = rt; vis[rt] = 1;
	while(front < tail) {
		int u = q[front++];
		Rep(i, G[u].size()) {
			if(!vis[G[u][i]]) {
				vis[G[u][i]] = 1;
				depth[G[u][i]] = lv;
				q[tail++] = G[u][i];
			}
		}
		lv++;
	}
}

void update(int rt, int p) {
	task[rt] = p;
	Rep(i, G[rt].size()) {
		update(G[rt][i], p);
	}
}

int main() {
	// FRead();
	int T, _ = 1;
	Rint(T);
	int u, v;
	char cmd[6];
	while(T--) {
		Rint(n);
		Rep(i, n+2) G[i].clear();
		Cls(depth); Cls(vis); Cls(in); Clr(task, -1);
		Rep(i, n-1) {
			Rint(u); Rint(v);
			G[v].push_back(u); in[u]++;
		}
		int rt = -1;
		For(i, 1, n+1) if(!in[i]) rt = i;
		// bfs(rt);
		Rint(m);
		printf("Case #%d:\n", _++);
		while(m--) {
			Rs(cmd);
			if(cmd[0] == 'C') {
				Rint(u);
				printf("%d\n", task[u]);
			}
			if(cmd[0] == 'T') {
				Rint(u); Rint(v);
				update(u, v);
			}
		}
	}
	return 0;
}