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

typedef struct P {
	int x;
	int y;
	int w;
	P() {}
	P(int xx, int yy, int ww) : x(xx), y(yy), w(ww) {}
}P;

const int maxn = 15;
const int inf = 0x7f7f;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n, m;
int ans;
bool vis[maxn][maxn];
char G[maxn][maxn];
vector<P> v;

int bfs(P a, P b) {
	int cur;
	queue<P> q;
	vis[a.x][a.y] = vis[b.x][b.y] = 1;

	q.push(a), q.push(b);
	while(!q.empty()) {
		P t = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			cur = t.w;
			int xx = t.x + dx[i];
			int yy = t.y + dy[i];
			if(xx >= 0 && yy >= 0 && xx < n && yy < m && !vis[xx][yy] && G[xx][yy] == '#') {
				vis[xx][yy] = 1;
				q.push(P(xx, yy, t.w+1));
			}
		}
	}
	return cur;
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		printf("Case %d: ", _);
		v.clear();
		ans = inf;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("%s", G[i]);
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(G[i][j] == '#') {
					v.push_back(P(i, j, 0));
				}
			}
		}
		for(int i = 0; i < v.size(); i++) {
			for(int j = i; j < v.size(); j++) {
				memset(vis, 0, sizeof(vis));
				int t = bfs(v[i], v[j]);
				int flag = 1;
				for(int k = 0; k < n; k++) {
					if(!flag) break;
					for(int l = 0; l < m; l++) {
						if(G[k][l] == '#' && !vis[k][l]) {
							flag = 0;
							break;
						}
					}
				}
				if(flag) {
					ans = min(ans, t);
				}
			}
		}
		if(ans == inf) {
			printf("-1\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
