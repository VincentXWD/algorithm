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

const int maxn = 1111;
int n, m;
int G[maxn][maxn];

int main() {
    // freopen("in", "r", stdin);
    int u, v;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            G[u][v] = 1;
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(G[i][k] && G[k][j]) {
                        G[i][j] = 1;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i<= n; i++) {
            int flag = 0;
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(!G[i][j] && !G[j][i]) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) cnt++;
        }
        printf("%d\n", cnt);
    }
}