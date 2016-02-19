#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>

using namespace std;

const int maxn = 10;
int n;
char G[maxn][maxn];
int ans;
int dd[4][2] = {1,0,0,1,-1,0,0,-1};

int ok(int x, int y) {
    int dx, dy;
    if(G[x][y] != '.') {
        return 0;
    }
    for(int i = 0; i < 4; i++) {
        dx = x + dd[i][0];
        dy = y + dd[i][1];
        while(1) {
            if(dx < 0 || dx >= n || dy < 0 || dy >= n || G[dx][dy] == 'X' || G[dx][dy] == 'x') {
                break;
            }
            else if(G[dx][dy] == 'B') {
                return 0;
            }
            dx += dd[i][0];
            dy += dd[i][1];
        }
    }
    return 1;
}

void dfs(int dep) {
    if(dep > ans) {
        ans = dep;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ok(i, j)) {
                G[i][j] = 'B';
                dfs(dep+1);
                G[i][j] = '.';
            }
        }
    }
}

int main() {
    while(~scanf("%d", &n) && n) {
        getchar();
        ans = 0;
        for(int i = 0; i < n; i++) {
            gets(G[i]);
        }
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}