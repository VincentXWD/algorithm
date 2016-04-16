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

#define MOD 2
#define MAXN 101

typedef struct MAT
{
    int d[MAXN][MAXN];
    int r, c;
    MAT() 
    {
        r = c = 0;
        memset(d, 0, sizeof(d));
    }
}MAT;

MAT mul(MAT m1, MAT m2, int mod)
{
    MAT ans = MAT();
    ans.r = m1.r;
    ans.c = m2.c;
    for(int i = 0; i < m1.r; i++)
    {
        for(int j = 0; j < m2.r; j++)
        {
            if(m1.d[i][j])
            {
                for(int k = 0; k < m2.c; k++)
                {
                    ans.d[i][k] = (ans.d[i][k] + m1.d[i][j] * m2.d[j][k]) % mod;
                }
            }
        }
    }
    return ans;
}

MAT quickmul(MAT m, int n, int mod)
{
    MAT ans = MAT();
    for(int i = 0; i < m.r; i++)
    {
        ans.d[i][i] = 1;
    }
    ans.r = m.r;
    ans.c = m.c;
    while(n)
    {
        if(n & 1)
        {
            ans = mul(m, ans, mod);
        }
        m = mul(m, m, mod);
        n >>= 1;
    }
    return ans;
}

int main() {
    int t;
    while(scanf("%d", &t) != EOF && t) {
        char T[105];
        scanf("%s", T);
        int n = strlen(T);
        MAT A, B, ans;
        A.r = 1, A.c = n;
        B.r = n, B.c = n;
        for(int i = 0; i < n; i++) {
            A.d[0][i] = T[i] - '0';
            B.d[i][i] = 1;
            B.d[i][(i+1)%n] = 1;
        }
        ans = quickmul(B, t, MOD);
        ans = mul(A, ans, MOD);
        for(int i = 0; i < n; i++) {
            printf("%d", ans.d[0][i]);
        }
        printf("\n");
    }
    return 0;
}