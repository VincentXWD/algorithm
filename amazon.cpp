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
char s[maxn];
char tmp[maxn];
int n;
int vis[maxn];

void dfs(int cur) {
    if(cur == n) {
        printf("%s\n", tmp);
        return;
    }
    for(int i = 0; i < 10; i++) {
        if(vis[i] > 0) {
            vis[i]--;
            tmp[cur] = i + '0';
            dfs(cur+1);
            vis[i]++;
            tmp[cur] = 0;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%s", s)) {
        memset(vis, 0, sizeof(vis));
        memset(tmp, 0, sizeof(tmp));
        n = strlen(s);
        sort(s, s+n);
        for(int i = 0; i < n; i++) vis[s[i]-'0']++;
        dfs(0);
    }
}