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
	int u;
	int v;
	int w;
}Node;

bool cmp(Node n1, Node n2) {
	return n1.w < n2.w;
}

const int maxn = 111;
Node node[6666];
int vis[maxn];
int n, m, u, v, w;
int pre[maxn];
int cnt, dig, flag, ans;

void init() {
	for(int i = 0; i <= maxn; i++) {
		pre[i] = i;
	}
}

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) pre[y] = x;
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		memset(vis, 0, sizeof(vis));
		memset(node, 0, sizeof(node));
		dig = 0;
		cnt = 0;
		flag = 0;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			node[i].u = u;
			node[i].v = v;
			node[i].w = w;
		}
		sort(node, node+m, cmp);
		for(int i = 0; i < m && cnt < n; i++) {
			if(find(node[i].u) != find(node[i].v)) {
				unite(node[i].u, node[i].v);
				vis[cnt++] = i;
				dig += node[i].w;
			}
		}
		ans = dig;

		for(int i = 1; i < n; i++) {
			init();
			cnt = n - 1;
			dig = 0;
			for(int j = 0; j < m && cnt; j++) {
				if(vis[i] != j && find(node[j].u) != find(node[j].v)) {
					unite(node[j].u, node[j].v);
					dig += node[j].w;
					cnt--;
					printf("%d\n", dig);
				}
			}
			if(cnt == 0 && dig == ans) {
				flag = 1;
				break;
			}
		}

		if(flag) printf("Not Unique!\n");
		else printf("%d\n", ans);
	}
}
