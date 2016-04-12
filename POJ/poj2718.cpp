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

const int maxn = 11;
int a[maxn], b[maxn], c[maxn];
int n, m, ans;
int k;
char tmp[maxn<<5];
bool vis[maxn];

void getp(int cnt, int cur) {
	do {
		if(c[0] == 0) continue;
		int tmp = 0;
		int j = 1;
		for(int i = cnt - 1; i >= 0; i--) {
			tmp += c[i] * j;
			j *= 10;
		}
		if(abs(cur - tmp) < ans) ans = abs(cur - tmp);
	}while(next_permutation(c, c + cnt));
}

void dfs(int cnt) {
	if(cnt > m) return;
	int tmp = 0;
	int j = 1; 
	if(cnt == m) {	
		if(b[0] != 0) {
			for(int i = cnt - 1; i >= 0; i--) {
				tmp += b[i] * j;
				j *= 10;
			}
			k = 0;
			for(int i = 0; i < n; i++) {
				if(!vis[i]) {
					c[k++] = a[i];
				}
			}

			getp(k, tmp);
		}
	}
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			b[cnt] = a[i];
			dfs(cnt+1);
			vis[i] = 0;
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	getchar();
	while(T--) {
		bool flag = 0;
		ans = 0x7f7f7f;
		n = 0;
		memset(vis, 0, sizeof(vis));
		gets(tmp);
		for(int i = 0; tmp[i]; i++) {
			if(tmp[i] != ' ') {
				a[n++] = tmp[i] - '0';
			}
			if(a[n-1] != 0) flag = 1;
		}
		if(!flag) {
			printf("0\n");
			continue;
		}
		if(n == 2 && (a[0] == 0 || a[1] == 0)) {
			printf("%d\n", abs(a[0] - a[1]));
			continue;
		}
		m = n / 2;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}