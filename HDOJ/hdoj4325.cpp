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

typedef struct Node {
	int s;
	int t;
}Node;

const int maxn = 1000010;
int n, m, cnt, tot;
int wt[maxn<<2];
int bit[maxn];
int ask[maxn];
Node f[maxn];

int lowbit(int x) {
	return x & (-x);
}

void add(int i, int x) {
	while(i <= cnt) {
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

int bs(int v) {
	int ll = 0, rr = cnt - 1;
	int mm;
	while(ll <= rr) {
		mm = (ll + rr) >> 1;
		if(wt[mm] == v) return mm;
		if(wt[mm] > v) rr = mm - 1;
		if(wt[mm] < v) ll = mm + 1;
	}
	return -1;
}

inline bool scan_d(int &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}

int main() {
	// freopen("in", "r", stdin);
	int T, _ = 1;
	scan_d(T);
	while(T--) {
		tot = 0;
		memset(bit, 0, sizeof(bit));
		scan_d(n); scan_d(m);
		for(int i = 1; i <= n; i++) {
			scan_d(f[i].s); scan_d(f[i].t);
			wt[tot++] = f[i].s; wt[tot++] = f[i].t;
		}
		for(int i = 1; i <= m; i++) {
			scan_d(ask[i]);
			wt[tot++] = ask[i];
		}
		sort(wt, wt+tot);
		// int tot = unique(wt,wt+tot) - wt;
		cnt = 1;
		for(int i = 1; i < tot; i++) {
			if(wt[i] != wt[i-1]) wt[cnt++] = wt[i];
		}
		for(int i = 1; i <= n; i++) {
			int x = bs(f[i].s) + 1;
			int y = bs(f[i].t) + 1;
			add(x, 1);
			add(y+1, -1);
		}
		printf("Case #%d:\n", _++);
		for(int i = 1; i <= m; i++) {
			int ans = bs(ask[i]) + 1;
			printf("%d\n", sum(ans));
		}
	}
	return 0;
}