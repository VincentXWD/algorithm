/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
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
#define fr first
#define sc second
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lp p << 1
#define rp p << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Edge {
	int u, v, next;
	Edge() {}
	Edge(int uu, int vv) : u(uu), v(vv) { next = -1; }
}Edge;
const int maxn = 10010;
const int maxm = 20020;
int n, m;
Edge edge[maxm];
int head[maxn];
int hcnt;
int pre[maxn];
int in[maxn];
int num, q[maxn], front, tail;
int uu[maxn], vv[maxn];
char cc[maxn][5];

void adde(int u, int v) {
	edge[hcnt] = Edge(u, v);
	edge[hcnt].next = head[u];
	head[u] = hcnt++;
	in[v]++;
}

int find(int x) {
	RT x == pre[x] ? x : pre[x] = find(pre[x]);
}

int unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx == fy) RT 0;
	if(x > y) pre[fy] = fx;
	else pre[fx] = fy;
	return 1;

}

int topo() {
	front = tail = 0;
	Rep(i, n) {
		if(in[i] == 0 && i == find(i)) {
			q[tail++] = i;
		}
	}
	int ret = 0;
	while(front < tail) {
		if(tail - front > 1) ret = 1;
		int u = q[front++];
		--num;
		for(int i = head[u]; ~i; i=edge[i].next) {
			int v = edge[i].v;
			if(--in[v] == 0) {
				q[tail++] = v;
			}
		}
	}
	if(num > 0) printf("CONFLICT\n");
	else if(ret) printf("UNCERTAIN\n");
	else printf("OK\n");
}

int main() {
	// FRead();
	int u, v;
	while(~Rint(n) && ~Rint(m)) {
		Cls(in); Clr(head, -1); hcnt = 0;
		num = n;
		Rep(i, n+5) pre[i] = i;
		Rep(i, m) {
			Rint(uu[i]); Rs(cc[i]); Rint(vv[i]);
			if(cc[i][0] == '=') {
				if(unite(uu[i], vv[i])) num--;
			}
		}
		Rep(i, m) {
			if(cc[i][0] != '=') {
				u = find(uu[i]); v = find(vv[i]);
				if(cc[i][0] == '>') adde(u, v);
				if(cc[i][0] == '<') adde(v, u);
			}
		}
		topo();
	}
	RT 0;
}
