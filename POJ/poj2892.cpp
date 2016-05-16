/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃ギリギリ♂ mind！
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
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 50050;
bool vis[maxn];
int bit[maxn];
int st[maxn], top;
int n, m;

int lowbit(int x) {
	return x & (-x);
}

void update(int i, int x) {
	while(i < maxn) {
		bit[i] += x;
		i += lowbit(i);
	}
}

int sum(int i) {
	int s = 0;
	while(i > 0) {
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}

int bs(int v, int n) {
	int l = 1, r = n + 1;
	int ret = n + 2;
	while(l <= r) {
		int m = (l + r) >> 1;
		if(sum(m) >= v) {
			ret = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return ret;
}

int main() {
	// FRead();
	int x;
	char cmd[5];
	while(~scanf("%d%d", &n, &m)) {
		Cls(vis); Cls(bit); top = 0;
		W(m) {
			Rs(cmd);
			if(cmd[0] == 'D') {
				Rint(x); x++;
				st[++top] = x;
				vis[x] = 1;
				update(x, 1);
			}
			if(cmd[0] == 'R') {
				x = st[top--];
				vis[x] = 0;
				update(x, -1);
			}
			if(cmd[0] == 'Q') {
				Rint(x); x++;
				if(vis[x]) {
					printf("0\n");
					continue;
				}
				x = sum(x);
				printf("%d\n", bs(x+1, n)-bs(x, n)-1);
			}
		}
	}
	return 0;
}
