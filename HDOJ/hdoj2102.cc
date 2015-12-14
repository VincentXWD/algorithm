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
	int z;
	int s;
	P() {}
	P(int xx, int yy, int zz, int ss) : x(xx), y(yy), z(zz), s(ss) {}
}P;

const int maxn = 15;
const int inf = 0x7f7f7f7f;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m, t, ans;
char G[3][maxn][maxn];
bool vis[3][maxn][maxn];
P s;

inline void init() {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < maxn; j++) {
			for(int k = 0; k < maxn; k++) {
				G[i][j][k] = '*';
			}
		}
	}
	ans = inf;
	s = P(inf, inf, inf, inf);
}

inline int min(int x, int y) {
	return x < y ? x : y;
}

bool judge(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m) {
		return 1;
	}
	return 0;
}

void bfs() {
	P q[maxn<<8];
	int front = 0, tail = 0;
	q[tail++] = s; vis[s.z][s.x][s.y] = 1;
	while(front < tail) {
		P tmp = q[front++];
		if(G[tmp.z][tmp.x][tmp.y] == 'P') {
			ans = min(ans, tmp.s);
			continue;
		}
		if(G[tmp.z][tmp.x][tmp.y] == '#') {
			if(!vis[!tmp.z][tmp.x][tmp.y]) {
				G[tmp.z][tmp.x][tmp.y] = '*';
				vis[!tmp.z][tmp.x][tmp.y] = 1;
				q[tail++] = P(tmp.x, tmp.y, !tmp.z, tmp.s);
			}
		}
		for(int i = 0; i < 4; i++) {
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if(G[tmp.z][xx][yy] != '*' && judge(xx, yy) && !vis[tmp.z][xx][yy]) {
				vis[tmp.z][xx][yy] = 1;
				q[tail++] = P(xx, yy, tmp.z, tmp.s+1);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		init();
		cin >> n >> m >> t;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < n; j++) {
				cin >> G[i][j];
			}
		}
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < m; k++) {
					if(G[i][j][k] == '#' && G[!i][j][k] == '*') {
						G[i][j][k] = '*';
					}
					if(G[i][j][k] == '#' && G[!i][j][k] == '#') {
						G[i][j][k] = '*';
						G[!i][j][k] = '*';
					}
					if(G[i][j][k] == 'S') {
						s = P(j, k, i, 0);
					}
				}
			}
		}
		if(s.x == inf) {
			cout << "NO" << endl;
			continue;
		}
		bfs();
		if(ans > t) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
