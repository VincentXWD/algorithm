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

typedef pair<int, int> PII;
typedef struct P {
	int x;
	int y;
	int s;
	P() {}
	P(int xx, int yy, int ss) : x(xx), y(yy), s(ss) {}
}P;

const int inf = 0x7f7f7f;
const int maxn  = 1001;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int r, c, jx, jy;
vector<PII> fir;
int ans;
int vis[maxn][maxn];
char G[maxn][maxn];

inline int min(int x, int y) {
	return x < y ? x : y;
}

bool judge(int x, int y) {
	if(!vis[x][y] && G[x][y] == '.' && x >= 0 && x < r && y >= 0 && y < c) {
		return 1;
	}
	return 0;
}

bool success(int x, int y) {
	if(G[x][y] == 'J' && 
	  (x == 0 || x == r - 1 || y == 0 || y == c - 1)) {
		return 1;
	}
	return 0;
}

void init() {
	memset(vis, 0, sizeof(vis));
	memset(G, 0, sizeof(G));
	ans = inf; 
	fir.clear();
}

void bfs() {
	P q[maxn<<8];
	int front = 0, tail = 0;
	int fcnt = 0, jcnt = 1, tmp = 0;
	for(int i = 0; i < fir.size(); i++) {
		q[tail++] = P(fir[i].first, fir[i].second, 0);
		vis[fir[i].first][fir[i].second] = 1;
		fcnt++;
	}
	q[tail++] = P(jx, jy, 0); vis[jx][jy] = 1;
	while(front < tail) {
		for(int k = 0; k < fcnt; k++) {
			P f = q[front++];
			for(int i = 0; i < 4; i++) {
				int xx = f.x + dx[i];
				int yy = f.y + dy[i];
				if(judge(xx, yy) && G[xx][yy] != 'F') {
					vis[xx][yy] = 1;
					if(G[xx][yy] != 'J') {
						G[xx][yy] = 'F';
					}
					q[tail++] = P(xx, yy, f.s+1); tmp++;
				}
			}
		}
		fcnt = tmp; tmp = 0;
		for(int k = 0; k < jcnt; k++) {
			P j = q[front++];
			if(success(j.x, j.y)) {
				ans = min(ans, j.s);
			}
			for(int i = 0; i < 4 ; i++) {
				int xx = j.x + dx[i];
				int yy = j.y + dy[i];
				if(judge(xx, yy) && G[xx][yy] != 'F') {
					vis[xx][yy] = 1;
					if(G[xx][yy] != 'F') {
						G[xx][yy] = 'J';
					}
					q[tail++] = P(xx, yy, j.s+1); tmp++;
				}
			}
		}
		jcnt = tmp; tmp = 0;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d %d", &r, &c);
		for(int i = 0; i < r; i++) {
			scanf("%s", G[i]);
		}
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(G[i][j] == 'J') {
					jx = i; jy = j;
				}
				if(G[i][j] == 'F') {
					fir.push_back(PII(i, j));
				}
			}
		}
		bfs();
		if(ans == inf) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", ans+1);
		}
	}
	return 0;
}

