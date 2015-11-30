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

char G[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

bool flag;

void init() {
	memset(G, 0, sizeof(G));
	memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
	memset(square, 0, sizeof(square));
	flag = 0;
}

int s(int r, int c) {
    if((r == 0 ||r == 1) && (c == 0 || c == 1)) return 1;
    if((r == 0 ||r == 1) && (c == 2 || c == 3)) return 2;
    if((r == 2 ||r == 3) && (c == 0 || c == 1)) return 3;
    if((r == 2 ||r == 3) && (c == 2 || c == 3)) return 4;
}

bool check(int r, int c, int n) {
    if(row[r][n])   return 0;
    if(col[c][n])   return 0;
    if(square[s(r,c)][n]) return 0;
    return 1;
}

void dfs(int cur) {
    if(cur == 16) {
        flag = 1;
        return;
    }
    int r = cur / 4;
    int c = cur % 4;
    if(G[r][c] == '*') {
        for(int i = 1; i <= 4; i++) {
            if(check(r, c, i)) {
                G[r][c] = i + '0';
                row[r][i] = 1;
                col[c][i] = 1;
                square[s(r,c)][i] = 1;
                dfs(cur + 1);
                if(flag) break;
                G[r][c] = '*';
                row[r][i] = 0;
                col[c][i] = 0;
                square[s(r,c)][i] = 0;
            }
        }
    }
    else dfs(cur + 1);
}

int main() {
    // freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		init();
		for(int i = 0; i < 4; i++) {
			scanf("%s", G[i]);
		}
		for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(G[i][j] != '*') {
                    row[i][G[i][j]-'0'] = 1;
                    col[j][G[i][j]-'0'] = 1;
                    square[s(i,j)][G[i][j]-'0'] = 1;
                }
            }
		}
        printf("Case #%d:\n", _);
		dfs(0);
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                printf("%c", G[i][j]);
            }
            printf("\n");
        }
	}
}
