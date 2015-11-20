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

typedef struct P {
	int u;
	int v;
	int w;
}P;

bool cmp1(P p1, P p2) {return p1.w < p2.w;}
bool cmp2(P p1, P p2) {return p1.w > p2.w;}
int A, B;

const int maxn = 100010;
int n, m, cnt;
int pre[maxn];
int fib[maxn];
P e[maxn];

int find(int x) {
	return x == pre[x] ? pre[x] : pre[x] = find(pre[x]);
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

void init() {
	for(int i = 0; i < maxn; i++) {
		pre[i] = i;
	}
}

void clear() {
	init();
	memset(e, 0, sizeof(e));
	A = 0, B = 0;
	cnt = 0;
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	fib[0] = 0, fib[1] = 1, fib[2] = 1;
	for(int i = 3; i <= 26; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		printf("Case #%d: ", _);
		clear();
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		}
		sort(e, e+m, cmp1);
		for(int i = 0; i < m; i++) {
			if(unite(e[i].u, e[i].v)) {
				A += e[i].w;
				cnt++;
			}
		}
		if(cnt != n - 1) printf("No\n");
		else {
			init();
			sort(e, e+m, cmp2);
			for(int i = 0; i < m; i++) {
				if(unite(e[i].u, e[i].v)) {
					B += e[i].w;
					cnt++;
				}
			}
			int flag = 0;
			for(int i = 1; i <= 25; i++) {
				if(fib[i] <= B && fib[i] >= A) {
					flag = 1;
					break;
				}
			}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
}
