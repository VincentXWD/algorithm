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
#define Rep(i, len) for(LL i = 0; i < (len); i++)
#define For(i, a, len) for(LL i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Fuint(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long Uint;
typedef pair<LL, LL> pii;
typedef pair<string, LL> psi;
typedef map<string, LL> msi;
typedef vector<LL> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 220;
int dp[maxn][maxn];
int a[maxn];
int n;

int main() {
	// FRead();
	while(~Rint(n)) {
		For(i, 1, n+1) Rint(a[i]);
		For(i, 2, n+1) a[i] += a[i-1];
		Cls(dp);
		for(int h = 2; h <= n; h++) {
			for(int i = 1; i <= n - h + 1; i++) {
				int j = i + h - 1;
				dp[i][j] = 0x7f7f7f;
				for(int k = i; k <= j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+a[j]-a[i-1]);
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	RT 0;
}