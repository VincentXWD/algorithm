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

const int maxn = 1010;
typedef struct Node {
    int u, v, w;
    Node() {}
    Node(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
    friend bool operator < (Node a, Node b) {
        return a.w > b.w;
    }
}Node;

int n, m;
int pre[maxn];
priority_queue<Node> pq;

void init() {
    for(int i = 0; i < maxn; i++) pre[i] = i;
    while(!pq.empty()) pq.pop();
}

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        pre[x] = y;
        return 1;
    }
    return 0;
}

int main() {
    // freopen("in", "r", stdin);
    int u, v, w;
    while(~scanf("%d %d", &n, &m)) {
        init();
        for(int i = 0; i < m + 1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            pq.push(Node(u, v, w));
        }
        int mst = 0;
        m++;
        while(m--) {
            if(unite(pq.top().u, pq.top().v)) {
                mst += pq.top().w;
            }
            pq.pop();
        }
        printf("%d\n", mst);
    }
    return 0;
}