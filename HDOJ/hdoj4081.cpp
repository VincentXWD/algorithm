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

typedef struct Node{
	int x;
	int y;
	double w;
}Node;

const int maxn = 1111;
int n, m, cnt;
int pre[maxn], vis[maxn], peo[maxn];
int x[maxn], y[maxn], p[maxn];
Node e[maxn<<4];
double mst;
bool use[maxn<<4];

bool cmp(Node n1, Node n2) {
	return n1.w < n2.w;
}

inline void clear() {
	memset(e, 0, sizeof(e));
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	memset(p, 0, sizeof(p));
	memset(vis, 0, sizeof(vis));
	memset(use, 0, sizeof(use));
	memset(peo, 0, sizeof(peo));
	m = 0, cnt = 0, mst = 0;
}

inline void init() {
	for(int i = 0; i < maxn; i++) pre[i] = i;
}

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[x] = y;
		return 1;
	}
	return 0;
}

double dis(int i, int j) {
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main() {
	freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		clear();
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &x[i], &y[i], &p[i]);
		}
		for(int i = 0; i < n - 1; i++) {
			for(int j = i + 1; j < n; j++) {
				e[m].x = i;
				e[m].y = j;
				e[m++].w = dis(i, j);
			}
		}
		init();
		sort(e, e+m, cmp);
		for(int i = 0; i < m; i++) {
			if(unite(e[i].x, e[i].y)) {
				vis[cnt] = i;
				mst += e[i].w;
				peo[cnt] += p[e[i].x] + p[e[i].y];
				cnt++;
			}
		}
		double ans = -1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i != j) {
					ans = max(ans, (p[i]+p[j]) / (mst-dis(i,j)));
				}
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
