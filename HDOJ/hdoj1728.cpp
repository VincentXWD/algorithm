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
	int x, y;
	int cnt;
	Node() { cnt = 0x7f7f; }
	Node(int xx, int yy) : x(xx), y(yy) { Node(); }
	Node(int xx, int yy, int cc) : x(xx), y(yy), cnt(cc) {}
}Node;

const int maxn = 111;
const int dx[5] = {1,-1,0,0};
const int dy[5] = {0,0,1,-1};
int n, m, k, flag;
int sx, sy, ex, ey;
int px, py;
bool vis[maxn][maxn];
char G[maxn][maxn];

void dfs(int x, int y, int cnt) {
    if(k < cnt) return;
    if(flag) return;
    if(k == cnt) {
    	if(!((x == ex) || (y == ey))) {
    		return;
    	}
    }
    if(x == ex && y == ey && k >= cnt) {
        flag = 1;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && yy >= 0 && xx < m && yy < n) {
            if(G[xx][yy] != '*' && !vis[xx][yy]) {
                vis[xx][yy] = 1;
                if(px != xx && py != yy) {
                    dfs(xx, yy, cnt+1);
                }
                else {
                    dfs(xx, yy, cnt);
                }
                vis[xx][yy] = 0;
                if(flag) return;
            }
        }
        px = x, py = y;
    }
}

void bfs() {
	Node que[maxn*maxn];
	int front = 0;
	int tail = 0;
	que[tail++] = Node(sx, sy, -1);
	vis[sx][sy] = 1;
	while(front < tail) {
		Node t = que[front++];
		if(t.cnt >= k) break;
		for(int i = 0; i < 4; i++) {
			Node tmp;
			tmp.x = t.x + dx[i];
			tmp.y = t.y + dy[i];
			tmp.cnt = t.cnt + 1;
			while(1) {
				if(tmp.x >= 0 && tmp.y >= 0 && tmp.x < m && tmp.y < n && G[tmp.x][tmp.y] != '*') {
                    if(tmp.x == ex && tmp.y == ey) {
                    	printf("yes\n");
                    	return;
                    }
                    if(!vis[tmp.x][tmp.y]) {
						vis[tmp.x][tmp.y] = 1;
						que[tail++] = tmp;
                    }
	                tmp.x += dx[i];
	                tmp.y += dy[i];

				}
				else break;
			}
		}
	}
	printf("no\n");
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &m, &n);
        memset(vis, 0, sizeof(vis));
        flag = 0;
        for(int i = 0; i < m; i++) {
            scanf("%s", G[i]);
        }
        scanf("%d %d %d %d %d", &k, &sy, &sx, &ey, &ex);
        sx--, sy--, ex--, ey--;
        px = sx, py = sy;
        if(abs(sx - ex) + abs(sy - ey) < k) {
        	puts("yes");
        	continue;
        }
        if(sx == ex && sx == ey) {
        	puts("yes");
        	continue;
        }
        // dfs(sx, sy, 0);
        bfs();
    }
    return 0;
}
