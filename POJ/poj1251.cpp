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

typedef struct Node {
    int a;
    int b;
    int v;
    friend bool operator < (Node a, Node b) {
        return a.v > b.v;
    }
}Node;

const int maxn = 20010;
int pre[maxn];
int n, ans;
Node p;
priority_queue<Node> pq;

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        pre[y] = x;
        return true;
    }
    return false;
}
inline void init() {
    for (int i = 0; i < maxn; i++) {
        pre[i] = i;
    }
    while (!pq.empty())    pq.pop();
}

int main() {
    // freopen("in", "r", stdin);
    while (~scanf("%d", &n) && n) {
        init();
        char a[2], b[2];
        int cnt = 0;
        int m, v;
        ans = 0;
        n--;
        for (int i = 0; i < n; i++) {
            scanf("%s %d", &a, &m);
            for (int i = 0; i < m; i++) {
                scanf("%s %d", &b, &v);
                p.a = a[0] - 'A';
                p.b = b[0] - 'A';
                p.v = v;
                pq.push(p);
            }
        }
        while (n) {
            p = pq.top();
            pq.pop();
            if (unite(p.a, p.b)) {
                n--;
                ans += p.v;
            }
        }
        printf("%d\n", ans);
    }
}