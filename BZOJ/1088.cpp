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

const int maxn = 11111;
int n;
int a[maxn];
int b[maxn];

int main() {
	// freopen("in", "r", stdin);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 1;
	if(a[1] == 0) {
		b[1] = b[2] = 0;
		ans = 1;
		for(int i = 3; i <= n + 1; i++) {
			b[i] = a[i-1] - b[i-1] - b[i-2];
		}
		if(b[n+1] != 0) ans--;
	}
	if(a[1] == 2) {
		b[1] = b[2] = 1;
		for(int i = 3; i <= n + 1; i++) {
			b[i] = a[i-1] - b[i-1] - b[i-2];
		}
		if(b[n+1] != 0) ans--;
	}
	if(a[1] == 1) {
		ans = 2;
		b[1] = 1;
		b[2] = 0;
		for(int i = 3; i <= n + 1; i++) {
			b[i] = a[i-1] - b[i-1] - b[i-2];
		}
		if(b[n+1] != 0) ans--;
		b[1] = 0;
		b[2] = 1;
		for(int i = 3; i <= n + 1; i++) {
			b[i] = a[i-1] - b[i-1] - b[i-2];
		}
		if(b[n+1] != 0) ans--;
	}
	printf("%d\n", ans);
	return 0;
}