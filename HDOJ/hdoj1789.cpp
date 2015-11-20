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
	int s, d;
};

bool cmp(P x, P y) {
	return x.s < y.s;
}

const int maxn = 1111;
int n;
int vis[maxn];
P p[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &p[i].d);
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &p[i].s);
		}
		sort(p, p + n, cmp);
		int j;
		for(int i = n - 1; i >= 0; i--) {
			for(j = p[i].d; j >= 0; j--) {
				if(!vis[j]) {
					vis[j] = 1;
					break;
				}
			}
			if(j <= 0) {
				cnt += p[i].s;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}