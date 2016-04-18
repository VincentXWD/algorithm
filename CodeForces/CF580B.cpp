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

typedef long long ll;
typedef struct Node {
	int m;
	int s;
}Node;
const int maxn = 100010;
int n, d;
Node f[maxn];

bool cmp(Node a, Node b) {
	if(a.m == b.m) return a.s > b.s;
	return a.m < b.m;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &d)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &f[i].m, &f[i].s);
		}
		sort(f+1, f+n+1, cmp);
		ll curans = 0;
		ll ans = 0;
		int front = 1;
		int tail = 1;
		while(1) {
			if(front > n || tail > n) break;
			if(f[tail].m - f[front].m >= d) 
				curans -= f[front++].s;
			else curans += f[tail++].s;
			ans = max(ans, curans);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}