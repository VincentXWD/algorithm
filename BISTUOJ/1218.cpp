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

const int maxn = 257;
char s[maxn];
char t[maxn];
int n;
int flag;

bool work(char c) {
	if(flag == 0) {
		if(c >= 'p' && c <= 'z') flag = 1;
		else return 0;
	}
	else if(flag == 1) {
		if(c == 'N') flag = 1;
		else if(c >= 'p' && c <= 'z') flag = 2;
		else return 0;
	}
	else if(flag == 2) {
		if((c >= 'C' && c <= 'E') || c == 'I') flag = 1;
		else if(c >= 'p' && c <= 'z') flag = 3;
		else return 0;
	}
	else if(flag == 3) {
		if((c >= 'C' && c <= 'E') || c == 'I') flag = 2;
		else return 0;
	}
	return 1;
}

//YM把这题看成词法分析问题，画出自动机的WT巨巨啊。
int main() {
	// FRead();
	int T;
	Rint(T);
	W(T) {
		flag = 0; Cls(t);
		Rs(s); n = strlen(s);
		Rep(i, n) t[i] = s[n-i-1];
		int i = 0;
		while(i < n && work(t[i])) i++;
		if(i == n && flag == 1) printf("YES\n");
		else printf("NO\n");
	}
	RT 0;
}