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

const int maxn = 666666;
int n, k;
int a[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &k)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ll = 1;
		int rr = 1;
		int rk = 0;
		int al = 0;
		int ar = 0;
		int ans = 0;
		while(rr <= n) {
			while(rr <= n && rk <= k) {
				if(!a[rr]) {
					if(rk == k) break;
					rk++;
				}
				rr++;
			}
			if(rr - ll > ans) {
				ans = rr - ll;
				al = ll;
				ar = rr - 1;
			}
			while(ll <= rr && a[ll]) ll++;
			rk--;
			ll++;
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n; i++) {
			if(i >= al && i <= ar) printf("1 ");
			else printf("%d ", a[i]);
		}
		printf("\n");
	}
}
