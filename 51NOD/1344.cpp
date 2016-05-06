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
const int maxn = 50050;
int n;
ll a[maxn];
ll sum[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%I64d", &a[i]);
		}
		sum[0] = a[0];
		ll ans = 0x7f7f7f;
		ans = min(sum[0], ans);
		for(int i = 1; i < n; i++) {
			sum[i] += sum[i-1] + a[i];
			ans = min(ans, sum[i]);
		}
		if(ans > 0) printf("0\n");
		else printf("%I64d\n", -ans);
	}
	return 0;
}