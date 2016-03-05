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
const int mod = 1e9+7;
const int maxn = 111111;
int n, m;
int s, t;
int a[5], b[5];
int d[11][maxn];
int q[maxn<<1];
int front, tail;
vector<int> e[maxn];

inline void init() {
    for(int i = 0; i <= 19 + n; i++) {
        e[i].clear();
    }
    for(int i = 1; i < n; i++) {
        e[i].push_back(i+1);
        e[i+1].push_back(i);
    }
}

void bfs(int s, int cnt) {
    memset(d[cnt], -1, sizeof(d[cnt]));
    front = tail = 0;
    q[tail++] = s;
    d[cnt][s] = 0;
    while(front < tail) {
        int u = q[front++];
        for(int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if(d[cnt][v] == -1) {
                d[cnt][v] = d[cnt][u] + 1;
                q[tail++] = v;
            }
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    init();
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        init();
        for(int i = 1; i <= 3; i++) {
            scanf("%d %d", &a[i], &b[i]);
            e[a[i]].push_back(b[i]);
            e[b[i]].push_back(a[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= 3; i++) {
            bfs(a[i], cnt++);
        }
        for(int i = 1; i <= 3; i++) {
            bfs(b[i], cnt++);
        }
        ll ans = 0;
        for(ll ii = 1; ii <= m; ii++) {
            scanf("%d %d", &s, &t);
            if(s < t) swap(s, t);
            ll tmp = s - t;
            for(int i = 0; i < cnt; i++) {
                if(d[i][s] + d[i][t] < tmp) {
                    tmp = d[i][s] + d[i][t];
                }
            }
            ans += (ll)ii * tmp;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}