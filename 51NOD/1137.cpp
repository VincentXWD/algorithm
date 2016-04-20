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

const int maxn = 111;
int n;
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &b[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}