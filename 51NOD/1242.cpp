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
const ll mod = 1000000009;
const ll maxn = 5;
ll n;

typedef struct Matrix {
    ll m[maxn][maxn];
    ll r;
    ll c;
    Matrix() {
        r = c = 0;
        memset(m, 0, sizeof(m));
    }
    Matrix(ll rr, ll cc) : r(rr), c(cc) {
    	memset(m, 0, sizeof(m));
    }
}Matrix;

Matrix mul(Matrix m1, Matrix m2, ll mod) {
    Matrix ans = Matrix();
    ans.r = m1.r;
    ans.c = m2.c;
    for(ll i = 1; i <= m1.r; i++) {
        for(ll j = 1; j <= m2.r; j++) {
               for(ll k = 1; k <= m2.c; k++) {
               	if(m2.m[j][k] == 0) continue;
                ans.m[i][k] = ((ans.m[i][k] + m1.m[i][j] * m2.m[j][k]) % mod) % mod;
            }
        }
    }
    return ans;
}

Matrix quickmul(Matrix m, ll n, ll mod) {
    Matrix ans = Matrix();
    ans.r = m.r;
    ans.c = m.c;
    for(ll i = 1; i <= m.r; i++) {
        ans.m[i][i]  = 1;
    }
    while(n) {
        if(n & 1) {
            ans = mul(m, ans, mod);
        }
        m = mul(m, m, mod);
        n >>= 1;
    }
    return ans;
}

int main() {
	// freopen("in", "r", stind);
	while(~scanf("%I64d", &n)) {
		Matrix s(2, 2);
		s.m[1][1] = 1; s.m[1][2] = 1;
		s.m[2][1] = 1; s.m[2][2] = 0;
		s = quickmul(s, n, mod);
		printf("%I64d\n", s.m[1][2]);
	}
}