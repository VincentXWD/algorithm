/*
组合数学或者dp均可求出
*/
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

typedef unsigned long long ull;

int n, m;
const ull mod = 10000000000007;
ull memo[1111][1111];

ull solve(int nn, int mm) {
	if(memo[nn][mm] != -1) return memo[nn][mm];
	if(mm > nn / 2) mm = nn - mm;
	return memo[nn][mm] = (solve(nn-1, mm-1) % mod + solve(nn-1, mm) % mod) % mod;
}

int main() {
	memset(memo, -1, sizeof(memo));
	for(int i = 0; i < 1111; i++) {
		memo[i][0] = 1;
		memo[i][1] = i;
		memo[i][i] = 1;
	}
    while(~scanf("%d %d", &n, &m)) {
        ull ans = 0;
        if(n == 1) {
        	printf("1\n");
        	continue;
        }
        int k = m / n;
        for(int i = 0; i <= k; i++) {
            ull p = m - i * n;
            ull q = i;
            if(p < q) swap(p, q);
            ans = (ans % mod + solve(p+q, q) % mod) % mod;
        }
        printf("%llu\n", ans % mod);
    }
    return 0;
}