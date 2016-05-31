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

const int maxn = 2000010;
int pre[maxn];
int id[maxn];
int sum[maxn];
int n, m;
int cnt, t;

int find(int x) {
	RT x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) pre[y] = x;
}

int main() {
	// FRead();
	char cmd[5];
	int a, b, _ = 1;
	while(~Rint(n) && ~Rint(m) && n + m) {
		cnt = n + 10; Cls(sum);
		Rep(i, maxn) id[i] = i, pre[i] = i;
		W(m) {
			Rs(cmd);
			if(cmd[0] == 'M') {
				Rint(a); Rint(b);
				unite(id[a], id[b]);
			}
			if(cmd[0] == 'S') {
				Rint(a);
				id[a] = cnt++;
			}
		}
		Rep(i, n) sum[i] = find(id[i]);
		sort(sum, sum+n); t = unique(sum, sum+n) - sum;
		printf("Case #%d: %d\n", _++, t);
	}
	RT 0;
}
