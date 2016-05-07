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

const int maxn = 100010;
int n, pcnt;
int pre[maxn];
char a[maxn], b[maxn];
map<string, int> peo;
map<string, int>::iterator it;

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	pre[x] = y;
}

int main() {
	// freopen("in", "r", stdin);
	int cmd;
	while(~scanf("%d", &n)) {
		for(int i = 0; i < maxn; i++) pre[i] = i;
		peo.clear();
		pcnt = 1;
		for(int i = 0; i < n; i++) {
			scanf("%d%s%s", &cmd, a, b);
			it = peo.find(string(a));
			if(it == peo.end()) peo[string(a)] = pcnt++;
			it = peo.find(string(b));
			if(it == peo.end()) peo[string(b)] = pcnt++;
			if(cmd == 0) unite(peo[a], peo[b]);
			else printf("%s\n", 
				find(peo[string(a)]) == find(peo[string(b)]) ? "yes" : "no");
		}
	}
	return 0;
}