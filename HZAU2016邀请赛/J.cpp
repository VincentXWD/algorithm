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
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 2020;
int h[maxn];
int ans;
int n;

int check(int d) {
	int ret = 0;
	int tmp = 0;
	for(int i = 1; i <= 2000; i++) {
		tmp = 0;
		if(h[i] == 0) continue;
		for(int j = i; j <= 2000; j+=d) {
			if(h[j]) tmp++;
			else break;
		}
		ret = max(tmp, ret);
	}
	return ret;
}

int main() {
	// FRead();
	int tmp;
	while(~Rint(n)) {
		Cls(h);
		ans = 0;
		Rep(i, n) {
			Rint(tmp);
			h[tmp]++;
		}
		//d = 0
		for(int i = 1; i <= 2000; i++) {
			ans = max(ans, h[i]);
		}
		for(int d = 1; d <= 2000; d++) {
			ans = max(ans, check(d));
		}
		cout << ans << endl;
	}
	return 0;
}