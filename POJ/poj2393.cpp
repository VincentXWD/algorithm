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
const int maxn = 10001;
int n, s;
int c[maxn], y[maxn];


int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &s)) {
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &c[i], &y[i]);
		}
		ll ans = c[0] * y[0];
		for(int i = 1; i < n; i++) {
			if(c[i-1] + s < c[i]) c[i] = s + c[i-1];
			ans += c[i] * y[i];
		}
		cout << ans << endl;
	}
	return 0;
}