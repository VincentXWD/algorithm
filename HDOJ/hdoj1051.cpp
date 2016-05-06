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
	int l, w;
}Node;

const int maxn = 5005;
int n, m, ans;
Node s[maxn];
Node f[maxn];
bool vis[maxn];

bool cmp(Node a, Node b) {
	if(a.l != b.l) return a.l < b.l;
	return a.w < b.w;
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		memset(s, 0, sizeof(s));
		memset(f, 0, sizeof(f));
		for(int i = 0; i < n; i++) {
			cin >> s[i].l >> s[i].w;
		}
		sort(s, s+n, cmp);
		ans = 0; m = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			if(vis[i]) continue;
			vis[i] = 1;
			f[m++] = s[i];
			for(int j = 0; j < n; j++) {
				if(!vis[j] && s[i].l <= s[j].l && s[i].w <= s[j].w) {
					vis[j] = 1;
					f[m++] = s[j];
				}
			}
		}
		ans++;
		for(int i = 1; i < m; i++) {
			if(f[i-1].w > f[i].w || f[i-1].l > f[i].l) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}