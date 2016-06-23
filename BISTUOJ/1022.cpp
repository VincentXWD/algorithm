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
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f7f, sizeof(a))
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

const int maxn = 1000100;
const int mod = 1000007;

typedef unsigned long long ull;
ull quickmul(int x, int n) {
	ull ans = 1;
	ull t = x;
	while(n) {
		if(n & 1) ans *= t;
		t *= t;
		n >>= 1;
	}
	return ans;
}

template<int B>
ull gethash(char* str, int n) {
	ull t = 0;
	for(int i = 0; i < n; i++) t = t * B + str[i];
	return t;
}
template<int B>
int judge(char* a, char* b) {
	int cnt = 0;
	int na = strlen(a);
	int nb = strlen(b);
	if(na > nb) return false;
	ull ha = gethash<B>(a, na);
	ull hb = gethash<B>(b, na);
	ull x = quickmul(B, na);
	for(int i = 0; i + na <= nb; i++) {
		if(ha == hb) cnt++;
		if(i + na < nb) hb = hb * B + b[i+na] - b[i] * x;
	}
	return cnt;
}

char a[maxn];
char b[maxn];

int main() {
	// FRead();
	int T;
	Rint(T);
	W(T) {
		Rs(a);
		Rs(b);
		printf("%d\n", judge<107>(a, b));
	}
	RT 0;
}