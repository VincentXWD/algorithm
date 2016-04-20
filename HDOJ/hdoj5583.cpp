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

typedef long long ll;
const int maxn = 100010;
int n;
char s[maxn];
ll grid[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		scanf("%s", s);
		memset(grid, 0, sizeof(grid));
		ll cur = 0, ans = 0;
		n = 0; grid[n] = 1;
		for(int i = 1; s[i]; i++) s[i] == s[i-1] ? grid[n]++ : grid[++n] = 1;
		for(int i = 0; i <= n; i++)	cur += grid[i] * grid[i];
		if(n == 0) ans = grid[0] * grid[0];
		else {
			for(int i = 1; i <= n; i++) {
				if(grid[i] == 1) ans = max(cur+2*(grid[i-1]*grid[i+1]+grid[i-1]+grid[i+1]), ans);
				else {
					if(grid[i-1] >= grid[i]) 
						ans = max(cur+2*(grid[i-1]-grid[i]+1), ans);
					else 
						ans = max(cur+2*(grid[i]-grid[i-1]+1), ans);
				}
			}
		}
		printf("Case #%d: %I64d\n", _, ans);
	}
	return 0;
}
