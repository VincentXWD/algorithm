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

const int dd[4][2] = {1,0,0,1,-1,0,0,-1};
char G[11][11];
bool vis[11][11];
bool pos[11][11];
int cnt, flag;

void init() {
    memset(G, 0, sizeof(G));
    memset(vis, 0, sizeof(vis));
    memset(pos, 0, sizeof(pos));
    cnt = 0;
    flag = 0;
}

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int xx = x + dd[i][0];
        int yy = y + dd[i][1];
        if(G[xx][yy] == '.' && !pos[xx][yy]) {
            if(xx >= 0 && xx < 9 && yy >= 0 && yy < 9) {
                cnt++;
                pos[xx][yy] = 1;
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        int xx = x + dd[i][0];
        int yy = y + dd[i][1];
        if(G[xx][yy] == 'o' && !vis[xx][yy]) {
            if(xx >= 0 && xx < 9 && yy >= 0 && yy < 9) {
                vis[xx][yy] = 1;
                dfs(xx, yy);
            }
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++) {
        init();
        for(int i = 0; i < 9; i++) {
            scanf("%s", G[i]) ;
        }
        // for(int i = 0; i < 9; i++) {
        //     printf("%s\n", G[i]);
        // }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(G[i][j] == 'o' && !vis[i][j]) {
                    memset(pos, 0, sizeof(pos));
                    vis[i][j] = 1;
                    cnt = 0;
                    dfs(i, j);
                    if(cnt == 1) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        printf("Case #%d: ", _);
        if(flag) printf("Can kill in one move!!!\n");
        else printf("Can not kill in one move!!!\n");
  }
}