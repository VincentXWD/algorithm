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

typedef struct Edge {
    int v;
    int w;
    int next;
    Edge() { next = -1; }
    Edge(int vv, int ww) : v(vv), w(ww) { next = -1; }
    friend bool operator <(Edge e1, Edge e2) {
    	return e1.w < e2.w;
    }
}Edge;

typedef pair<int, int> PII;
typedef long long ll;
const ll inf = 0x7fffffff;
const int maxn = 1000010;

int n, m;
int cnt;
int head[maxn];
int head1[maxn];
ll d[maxn];
ll d1[maxn];
Edge e1[maxn];
Edge e2[maxn];

priority_queue<PII, vector<PII>, greater<PII> > pq;

void init() {
    memset(e1, 0, sizeof(e1));
    memset(e2, 0, sizeof(e2));
    memset(head, -1, sizeof(head));
    memset(head1, -1, sizeof(head1));
    cnt = 0;
}

void adde(Edge* e1, int* head, int uu, int vv, int ww) {
    e1[cnt].v = vv;
    e1[cnt].w = ww;
    e1[cnt].next = head[uu];
    head[uu] = cnt++;
}

void dijkstra(int s, Edge* e1, int* head, ll* d) {
	for(int i = 0; i <= n; i++) d[i] = inf;
	while(!pq.empty()) pq.pop();
	d[s] = 0;
	pq.push(PII(0, s));
	while(!pq.empty()) {
		PII cur = pq.top(); pq.pop();
		int v = cur.second;
		if(d[v] < cur.first) continue;
		for(int i = head[v]; ~i; i=e1[i].next) {
			int w = e1[i].w;
			if(d[e1[i].v] > d[v] + w) {
				d[e1[i].v] = d[v] + w;
				pq.push(PII(d[e1[i].v], e1[i].v));
			}
		}
	}
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    int uu, vv, ww;
    scanf("%d", &T);
    while(T--) {
    	scanf("%d %d", &n, &m);
    	init();
    	for(int i = 0; i < m; i++) {
    		scanf("%d %d %d", &uu, &vv, &ww);
    		adde(e1, head, uu, vv, ww);
    		adde(e2, head1, vv, uu, ww);
    	}
    	dijkstra(1, e1, head, d);
    	dijkstra(1, e2, head1, d1);
    	ll ans = 0;
    	for(int i = 1; i <= n; i++) {
    		ans += d[i] + d1[i];
    	}
    	printf("%I64d\n", ans);
    }
}
