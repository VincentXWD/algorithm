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
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 2000202;
int sum[maxn<<2];
int h, w, n;
void pushUP(int rt) {
	sum[rt] = max(sum[lrt], sum[rrt]);
}

void build(int l, int r, int rt) {
	sum[rt] = w;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
}

int query(int x, int l, int r, int rt) {
	if(l == r) {
		sum[rt] -= x;
		return l;
	}
	int m = (l + r) >> 1;
	int ret = (sum[lrt] >= x) ? query(x, l, m, lrt) : query(x, m+1, r, rrt);
	pushUP(rt);
	return ret;
}

int main() {
	// FRead();
	int x;
	while(~Rint(h) && ~Rint(w) && ~Rint(n)) {
		if(h > n) h = n;
		build(1, h, 1);
		W(n) {
			Rint(x);
			if(sum[1] < x) printf("-1\n");
			else printf("%d\n", query(x, 1, h, 1));
		}
	}
	RT 0;
}