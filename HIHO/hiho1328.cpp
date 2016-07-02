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
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Node {
	int x, y;
	int s;
	int k;
	Node() {}
	Node(int xx, int yy, int ss, int kk) : x(xx), y(yy), s(ss), k(kk) {}
}Node;
const int dx[5] = {1,-1,0,0};
const int dy[5] = {0,0,1,-1};
const int maxn = 110;
int n, m, k;
int sx, sy, ex, ey;
int vis[maxn][maxn][33];
char G[maxn][maxn];
char ks[maxn][maxn];
int ret;
queue<Node> q;

bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && G[x][y] != '#';
}

bool yes(int x, int y, int k) {
	if(G[x][y] == '.') return 1;
	return k & (1 << (G[x][y] - 'A'));
}

void bfs() {
	while(!q.empty()) q.pop();
	q.push(Node(sx, sy, 0, 0));
	vis[sx][sy][0] = 0;
	while(!q.empty()) {
		Node t = q.front(); q.pop();
		// printf("%d\n", t.k);
		if(t.x == ex && t.y == ey) {
			ret = min(ret, t.s);
			return;
		}
		Rep(i, 4) {
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if(ok(x, y)) {
				int ck =  t.k | ks[x][y];
				if(vis[x][y][ck] > t.s + 1 && yes(x, y, ck)) {
					vis[x][y][ck] = t.s + 1;
					q.push(Node(x, y, t.s+1, ck));
				}
			}
		}
	}
}

int main() {
	// FRead();
	int x, y;
	while(~scanf("%d%d%d%d%d%d%d",&n,&m,&k,&sx,&sy,&ex,&ey)) {
		Clr(vis, 0x7f7f); Cls(G); Cls(ks); ret = 0x7f7f;
		Rep(i, n) Rs(G[i]);
		Rep(i, k) {
			Rint(x); Rint(y);
			ks[x][y] |= (1 << i);
		}
		bfs();
		if(ret != 0x7f7f) printf("%d\n", ret);
		else printf("-1\n");
	}
	RT 0;
}