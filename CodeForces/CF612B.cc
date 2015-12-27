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

typedef long long LL;
const int maxn = 2222222;
int n;
int f[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		int x;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			f[x] = i;
		}
		LL ans = 0;
		for(int i = 2; i <= n; i++) {
			ans += abs(f[i] - f[i-1]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}