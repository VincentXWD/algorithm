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
const int dx[5] = {1, -1, 0, 0};
const int dy[5] = {0, 0, 1, -1};

int a[maxn][maxn];
set<vector<int> > vis;
vector<int> tmp;

bool ok(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}

void dfs(int x, int y, vector<int> t) {
	if(t.size() > 6) return;
	if(t.size() == 6) {
		if(vis.find(t) == vis.end()) {
			vis.insert(t);
		}
		t.clear();
		return;
	}
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(ok(xx, yy)) {
			t.push_back(a[xx][yy]);
			dfs(xx, yy, t);
			t.pop_back();
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	vis.clear();
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			tmp.clear();
			dfs(i, j, tmp);
		}
	}
	printf("%d\n", vis.size());
	return 0;
}
