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
int G[maxn], ans[maxn];
bool vis[maxn];
int cnt, cur;

bool ok() {
	for(int i = 0; i < 7; i+=3)
		if(G[i] + G[i+1] + G[i+2] != 15)  return 0;
	for(int i = 0; i < 3; i++)
		if(G[i] + G[i+3] + G[i+6] != 15)  return 0;
	if(G[0]+G[4]+G[8]!=15||G[2]+G[4]+G[6]!=15) return 0;
	return 1;
}

void dfs(int cur) {
	if(cur == 9) {
		if(ok()) {
			cnt++;
			if(cnt == 1) {
				for(int i = 0; i < 9; i++)
					ans[i] = G[i];
			}
		}
		return;
	}
	if(G[cur]) dfs(cur + 1);
	else {		
		for(int i = 1; i <= 9; i++) {
			if(!vis[i]) {
				vis[i] = 1;
				G[cur] = i;
				dfs(cur + 1);
				vis[i] = 0;
				G[cur] = 0;
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &G[0])) {
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		vis[G[0]] = 1;
		for(int i = 1; i < 9; i++) {
			scanf("%d", &G[i]);
			vis[G[i]] = 1;
		}
		dfs(0);
		if(cnt == 1) {
			for(int i = 0; i < 9; i++) {
				printf("%d ", ans[i]);
				if(i != 0 && (i + 1) % 3 == 0) printf("\n");
			}
		}
		else printf("Too Many\n");
	}
	return 0;
}