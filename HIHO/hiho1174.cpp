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

const int maxn = 100100;
const int maxm = 500500;
typedef struct Edge {
	int u, v;
	int next;
}Edge;
Edge edge[maxm];
int ecnt, head[maxn];
int n, m;
int dig[maxn];
priority_queue<int, vector<int>, greater<int> > pq;

void adde(int u, int v) {
	edge[ecnt].u = u;
	edge[ecnt].v = v;
	edge[ecnt].next = head[u];
	head[u] = ecnt++;
}

int main() {
	// FRead();
	int T, u, v;
	Rint(T);
	W(T) {
		ecnt = 0; Clr(head, -1); Cls(dig);
		Rint(n); Rint(m);
		Rep(i, m) {
			Rint(u); Rint(v);
			adde(u, v);
			dig[v]++;
		}
		while(!pq.empty()) pq.pop();
		For(i, 1, n+1) if(dig[i] == 0) pq.push(i);
		int cnt = n;
		while(!pq.empty()) {
			u = pq.top(); pq.pop();
			cnt--;
			for(int i = head[u]; ~i; i=edge[i].next) {
				v = edge[i].v;
				if(--dig[v] == 0) pq.push(v);
			}
		}
		if(cnt != 0) printf("Wrong\n");
		else printf("Correct\n");
	}
	RT 0;
}