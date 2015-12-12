/*
时间要求很严格
贪心+bfs，先找二进制最小的数
再统计里面的1的数量
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

typedef pair<int, int> PII;
const int maxn = 1010;
const int inf = 0x7f7f7f;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char G[maxn][maxn];
bool vis[maxn][maxn];
int n, m, ans;

inline int max(int x, int y) {
    return x > y ? x : y;
}

inline int min(int x, int y) {
    return x < y ? x : y;
}

bool judge(int x, int y) {
    if(x >= 1 && x <= n && y >= 1 && y <= m) {
        return 1;
    }
    return 0;
}

void bfs() {
    int mx = 2;
    queue<PII> q;
    memset(vis, 0, sizeof(vis));
    q.push(PII(1, 1)); vis[1][1] = 1;
    while(!q.empty()) {
        PII t = q.front(); q.pop();
        if(G[t.first][t.second] == '0') {
            for(int i = 0; i < 4; i++) {
                int xx = t.first + dx[i];
                int yy = t.second + dy[i];
                if(judge(xx, yy) && !vis[xx][yy]) {
                    vis[xx][yy] = 1;
                    mx = max(mx, xx+yy);
                    q.push(PII(xx, yy));
                }
            }
        }
    }
    if(vis[n][m] && G[n][m] == '0') {
        printf("0\n");
    }
    else {
        ans += 1;
        for(int i = mx; i < n + m; i++) {
            char mn = '1';
            for(int j = 1; j <= n; j++) {
                if(1 <= i - j && i - j <= m && vis[j][i-j]) {
                    mn = min(mn, min(G[j][i-j+1], G[j+1][i-j]));
                }
            }
            ans += mn - '0';
            for(int j = 1; j <= n; j++) {
                if(1 <= i - j && i - j <= m && vis[j][i-j]) {
                    if (G[j+1][i-j] == mn) {
                        vis[j+1][i-j] = 1;
                    }
                    if (G[j][i-j+1] == mn) {
                        vis[j][i-j+1] = 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%s", G[i]+1);
        }
        for(int i = 1; i <= n; i++) {
            G[i][0] = G[i][m+1] = '@';
        }
        for(int i = 0; i <= m + 1; i++) {
            G[0][i] = G[n+1][i] = '@';
        }
        bfs();
     }
    return 0;
}
