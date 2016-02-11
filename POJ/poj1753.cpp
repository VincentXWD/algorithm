#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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

const int maxn = 0xffff + 10;
char G[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int status;
int flip[20];
int n;
bool vis[maxn];

typedef struct Node {
    int status;
    int step;
    Node() {}
    Node(int ss, int tt) : status(ss), step(tt) {}
}Node;

bool judge(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void init() {
    int tmp;
    n = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tmp = 0;
            tmp ^= (1 << ((3 - i) * 4 + 3 - j));
            for(int t = 0; t < 4; t++) {
                int x = i + dx[t];
                int y = j + dy[t];
                if(judge(x, y)) {
                    tmp ^= (1 << ((3 - x) * 4 + 3 - y));
                }
            }
            flip[n++] = tmp;
        }
    }
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    Node q[maxn];
    int front = 0, tail = 0;
    Node cur(status, 0);
    q[tail++] = cur; vis[status] = 1;
    while(front < tail) {
        cur = q[front++];
        if(cur.status == 0 || cur.status == 0xffff) {
            return cur.step;
        }
        for(int i = 0; i < 16; i++) {
            Node tmp;
            tmp.status = cur.status ^ flip[i];
            tmp.step = cur.step + 1;
            if(vis[tmp.status]) {
                continue;
            }
            if(tmp.status == 0 || tmp.status == 0xffff) {
                return tmp.step;
            }
            vis[tmp.status] = 1;
            q[tail++] = tmp;
        }
    }
    return -1;
}

int main() {
    // freopen("in", "r", stdin);
    init();
    memset(G, 0, sizeof(G));
    while(~scanf("%s", G[0])) {
        status = 0;
        for(int i = 1; i < 4; i++) {
            scanf("%s", G[i]);
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                status <<= 1;
                if(G[i][j] == 'b') {
                    status |= 1;
                }
            }
        }
        int ans = bfs();
        if(ans == -1) {
            printf("Impossible\n");
        }
        else {
            printf("%d\n", ans);
        }
        memset(G, 0, sizeof(G));
    }
    return 0;
}