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

const int maxn = 10;
typedef struct Matrix {
    int m[maxn][maxn];
    int r;
    int c;
    Matrix(){
        r = c = 0;
        memset(m, 0, sizeof(m));
    } 
} Matrix;

Matrix mul(Matrix m1, Matrix m2, int mod) {
    Matrix ans = Matrix();
    ans.r = m1.r;
    ans.c = m2.c;
    for(int i = 1; i <= m1.r; i++) {
        for(int j = 1; j <= m2.r; j++) {
               for(int k = 1; k <= m2.c; k++) {
                if(m2.m[j][k] == 0) continue;
                ans.m[i][k] = ((ans.m[i][k] + m1.m[i][j] * m2.m[j][k] % mod) % mod) % mod;
            }
        }
    }
    return ans;
}

Matrix quickmul(Matrix m, int n, int mod) {
    Matrix ans = Matrix();
    for(int i = 1; i <= m.r; i++) {
        ans.m[i][i]  = 1;
    }
    ans.r = m.r;
    ans.c = m.c;
    while(n) {
        if(n & 1) {
            ans = mul(m, ans, mod);
        }
        m = mul(m, m, mod);
        n >>= 1;
    }
    return ans;
}

int n, m;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		Matrix p;
		p.r = 4, p.c = 1;
		p.m[1][1] = 9;
		p.m[2][1] = 6;
		p.m[3][1] = 4;
		p.m[4][1] = 2;
		if(n <= 4) {
			printf("%d\n", p.m[4-n+1][1] % m);
			continue;
		}
		Matrix s;
		s.r = s.c = 4;
		s.m[1][1] = 1; s.m[1][2] = 0, s.m[1][3] = 1, s.m[1][4] = 1;
		s.m[2][1] = 1; s.m[2][2] = 0, s.m[2][3] = 0, s.m[2][4] = 0;
		s.m[3][1] = 0; s.m[3][2] = 1, s.m[3][3] = 0, s.m[3][4] = 0;
		s.m[4][1] = 0; s.m[4][2] = 0, s.m[4][3] = 1, s.m[4][4] = 0;
		s = quickmul(s, n-4, m);
		int ans = 0;
		for(int i = 1; i <= p.r; i++) {
			ans = (ans + (p.m[i][1] * s.m[1][i]) % m) % m;
		}
	    printf("%d\n", ans % m);
	}
	return 0;
}