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
	int u;
	int v;
	int next;
	Edge() { next = -1; }
}Edge;
const int maxn = 100100;
const int maxm = 100100;
int n, m;
int head[maxn], ecnt;
Edge edge[maxm];
int bcnt, dindex;
int dfn[maxn], low[maxn];
int stk[maxn], top;
int belong[maxn], num[maxn];
int in[maxn], out[maxn];
bool instk[maxn];

void init() {
	Clr(head, -1);
	Cls(edge); Cls(instk);
	Cls(dfn); Cls(low); Cls(num);
	Cls(belong); Cls(in); Cls(out);
	ecnt = top = bcnt = dindex = 0;
}

void adde(int uu, int vv) {
	edge[ecnt].u = uu;
	edge[ecnt].v = vv;
	edge[ecnt].next = head[uu];
	head[uu] = ecnt++;
}

void tarjan(int u) {
	int v = u;
	dfn[u] = low[u] = ++dindex;
	stk[++top] = u;
	instk[u] = 1;
	for(int i = head[u]; ~i; i=edge[i].next) {
		v = edge[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instk[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		bcnt++;
		do {
			v = stk[top--];
			instk[v] = 0;
			belong[v] = bcnt;
		} while(v != u);
	}
}

int main() {
	// FRead();
	int T, _ = 1, u, v;
	Rint(T);
	W(T) {
		printf("Case %d: ", _++);
		init();
		Rint(n); Rint(m);
		Rep(i, m) {
			Rint(u); Rint(v);
			adde(u, v);
		}
		For(i, 1, n+1) if(!dfn[i]) tarjan(i);
		if(bcnt == 1) {
			printf("-1\n");
			continue;
		}
		For(u, 1, n+1) {
			num[belong[u]]++;
			for(int i = head[u]; ~i; i=edge[i].next) {
				int v = edge[i].v;
				if(belong[u] != belong[v]) {
					in[belong[v]]++; out[belong[u]]++;
				}
			}
		}
		int ret = 0;
		For(i, 1, bcnt+1) {
			if(in[i] == 0 || out[i] == 0) {
				ret = max(ret, n*(n-1)-m-num[i]*(n-num[i]));
			}
		}
		printf("%d\n", ret);
	}
	RT 0;
}