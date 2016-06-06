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

typedef struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}
}Point;
const int inf = 0x7f7f7f7f;
const int maxn = 222;
const int n = 8;
const int dx[9] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[9] = {2, 1, -1, -2, -2, -1, 1, 2};
vector<Point> knight;
char cmd[5];
int path[5][maxn][maxn];
Point q[1111111];
int front, tail;
bool vis[maxn][maxn];

bool ok(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

void bfs(Point s, int p) {
	Rep(i, n) Rep(j, n) path[p][i][j] = inf;
	Cls(vis); front = tail = 0;
	q[tail++] = s;
	path[p][s.x][s.y] = 0;
	vis[s.x][s.y] = 1;
	while(front < tail) {
		Point t = q[front++];
		Rep(i, n) {
			int tx = t.x + dx[i];
			int ty = t.y + dy[i];
			if(ok(tx, ty) && !vis[tx][ty]) {
				vis[tx][ty] = 1;
				path[p][tx][ty] = path[p][t.x][t.y] + 1;
				q[tail++] = Point(tx, ty);
			}
		}
	}
}

int main() {
	// FRead();
	int T;
	Rint(T);
	W(T) {
		knight.cl();
		Rep(i, 3) {
			Rs(cmd);
			knight.pb(Point(cmd[0]-'A', cmd[1]-'1'));
		}
		Rep(i, 3) bfs(knight[i], i);
		int ret = inf;
		Rep(i, n) {
			Rep(j, n) {
				int tmp = 0;
				Rep(p, 3) {
					tmp += path[p][i][j];
				}
				ret = min(ret, tmp);
			}
		}
		printf("%d\n", ret);
	}
	RT 0;
}