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

const int maxn = 110;
int n, m, p;
int a[maxn], b[maxn], c[maxn];

bool bs(int* x, int ll, int rr, int val) {
	int mm = (ll + rr) >> 1;
	while(ll <= rr) {
		int mm = (ll + rr) >> 1;
		if(x[mm] == val) return 1;
		if(x[mm] > val) rr = mm - 1;
		if(x[mm] < val) ll = mm + 1;
	}
	return 0;
}

int main() {
	// FRead();
	while(~Rint(n) && ~Rint(m) && n + m) {
		p = 0;
		Rep(i, n) Rint(a[i]);
		Rep(i, m) Rint(b[i]);
		sort(a, a+n); sort(b, b+m);
		Rep(i, n) if(!bs(b, 0, m-1, a[i])) c[p++] = a[i];
		if(p == 0) printf("NULL\n");
		else {
			Rep(i, p) printf("%d ", c[i]);
			printf("\n");
		}
	}
	RT 0;
}