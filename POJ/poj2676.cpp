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


const int n = 9;
const int maxn = n + 5;
const int s[maxn][maxn] = {
	{1,1,1,2,2,2,3,3,3},
	{1,1,1,2,2,2,3,3,3},
	{1,1,1,2,2,2,3,3,3},
	{4,4,4,5,5,5,6,6,6},
	{4,4,4,5,5,5,6,6,6},
	{4,4,4,5,5,5,6,6,6},
	{7,7,7,8,8,8,9,9,9},
	{7,7,7,8,8,8,9,9,9},
	{7,7,7,8,8,8,9,9,9}
};
/*
   0 1 2 3 4 5 6 7 8
   ------------------
0| 1 1 1 2 2 2 3 3 3
1| 1 1 1 2 2 2 3 3 3
2| 1 1 1 2 2 2 3 3 3
3| 4 4 4 5 5 5 6 6 6
4| 4 4 4 5 5 5 6 6 6
5| 4 4 4 5 5 5 6 6 6
6| 7 7 7 8 8 8 9 9 9
7| 7 7 7 8 8 8 9 9 9
8| 7 7 7 8 8 8 9 9 9
*/

char G[maxn][maxn];
bool row[maxn][maxn];
bool col[maxn][maxn];
bool squ[maxn][maxn];
bool flag;

inline void init() {
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(squ, 0, sizeof(squ));
	flag = 0;
}

bool check(int r, int c, int x) {
    if(row[r][x])   return 0;
    if(col[c][x])   return 0;
    if(squ[s[r][c]][x]) return 0;
    return 1;
}

void dfs(int cur) {
	if(cur == n * n) {
		flag = 1;
		return;
	}
	int r = cur / n;
	int c = cur % n;
	if(G[r][c] == '0') {
		for(int i = 1; i <= 9; i++) {
			if(check(r, c, i)) {
				G[r][c] = i + '0';
				row[r][i] = col[c][i] = squ[s[r][c]][i] = 1;
				dfs(cur + 1);
				if(flag) break;
				G[r][c] = '0';
				row[r][i] = col[c][i] = squ[s[r][c]][i] = 0;
			}
		}
	}
	else {
		dfs(cur + 1);
	}
}

inline void show() {
	for(int i = 0; i < n; i++) {
		printf("%s\n", G[i]);
	}
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		for(int r = 0; r < n; r++) {
			scanf("%s", G[r]);
		}
		for(int r = 0; r < n; r++) {
			for(int c = 0; c < n; c++) {
				if(G[r][c] == '0') continue;
                    row[r][G[r][c]-'0'] = 1;
                    col[c][G[r][c]-'0'] = 1;
                    squ[s[r][c]][G[r][c]-'0'] = 1;
			}
		}
		dfs(0);
		show();
	}
	return 0;
}