#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


const int maxn = 100010;
typedef vector<int> VI;
VI ve[maxn];
bool vis[maxn];
int sta[maxn], top;
int n, qq;
int pre[maxn];

void dfsTopo(int u) {
    vis[u] = true;
    for(int i = 0; i < ve[u].size(); i ++ )
           if(!vis[ve[u][i]]) {
               dfsTopo(ve[u][i]);
           }
    sta[top++] = u;
}

void Toposort(int n) {
    memset(vis, 0, sizeof(vis));
    top = 0;
    for(int i = 1; i <= n; i ++ )
        if(!vis[i]) {
        	dfsTopo(i);
        }
}


int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[y] = x;
	}
}
inline void init() {
	for(int i = 0; i < maxn; i++) {
		pre[i] = i;
	}
}


int main() {
	freopen("in", "r", stdin);
	int a, b;
	while(~scanf("%d", &n)) {
		init();
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n - 1; i++) {
			scanf("%d %d", &a, &b);
			unite(a, b);
			ve[a].push_back(b);
		}
		Toposort(n);
		for(int i = 0; i < n; i++){
			printf("%d ", sta[i]);
		}
		printf("\n");
		scanf("%d", &qq);
		while(qq--) {
			int flag = 0;
			scanf("%d %d", &a, &b);
			for(int i = 0; sta[i] < a; i++) {
				if(sta[i] == b && ve[i].size() < ve[a].size()) {
					flag = 1;
				}
			}

			if(flag) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
}
