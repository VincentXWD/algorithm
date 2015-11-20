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

const int maxn = 2222;
int n, m, k, ans;
char G[maxn][maxn];
char N[maxn][maxn];
int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
int block[maxn*maxn];

bool bound(int x, int y) {
    if((x < 0 || x > n) || (y < 0 || y > m)) {
        return 0;
    }
    return 1;
}

void dfs(int x, int y, int cnt) {
    N[x][y] = cnt;
    G[x][y] = '$';
    if(G[x+1][y] == '*') block[cnt]++;
    if(G[x-1][y] == '*') block[cnt]++;
    if(G[x][y+1] == '*') block[cnt]++;
    if(G[x][y-1] == '*') block[cnt]++;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(bound(xx, yy) && G[xx][yy] == '.') {
            dfs(xx, yy, cnt);
        }
    }
}

int main() {
    int xx, yy;
    // freopen("in", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    memset(G, 0, sizeof(G));
    memset(N, 0, sizeof(N));
    memset(block, 0, sizeof(block));
    for(int i = 0; i < n; i++) {
        scanf("%s", G[i]);
    }
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '.') {
                dfs(i, j, cnt++);
            }
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &xx, &yy);
        xx--, yy--;
        printf("%d\n", block[N[xx][yy]]);
    }
    return 0;
}
