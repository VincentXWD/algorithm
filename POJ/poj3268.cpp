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
#include <cmath>

using namespace std;


const int maxn = 1001;
const int inf = 0x7ffffff;
int G[maxn][maxn];
int d[maxn];
int vis[maxn];
int b[maxn];
int s,e,v;
int n,m,i,j,x;

int findMin(int n) {
    int minNode  = 0;
    int min = inf;
    for(int i = 1;i <= n;i++)
        if(!vis[i] && d[i] < min) {
            minNode = i;
            min = d[i];
        }
    return minNode;
}


void dijkstra(int n,int x) {
    int i,vnum;
    memset(vis,false,sizeof(vis));
    for(i = 1;i <= n;i++) {
        d[i] = G[x][i];
    }
    vis[x] = 1;
    vnum = 1;
    while(vnum  < n) {
        int x = findMin(n);
        if(x) {
            vis[x] = 1;
            vnum++;
            for(i = 1; i <= n; i++)
                if(!vis[i] && d[x] + G[x][i] < d[i])
                    d[i] = G[x][i] + d[x];
        }
        else break;
    }
}

int findMax(int n) {
    int max = 0;
    for(int i = 1; i <= n; i++)
        if(max < b[i]) max = b[i];
    return max;
}


void init(int n) {
    for(int i = 0; i <= n; i++) {
        b[i] = 0;
        for(int j = 0; j <= n; j++) {
            G[i][j] = inf;
        }
    }
    memset(vis, false, sizeof(vis));

}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d %d %d", &n, &m, &x);
    init(n);
    for(i = 0;i < m;i++) {
        scanf("%d %d %d",&s, &e, &v);
        G[s][e] = v;
    }
    dijkstra(n,x);
    for(i = 1;i <= n;i++) {
        d[i] != inf ? b[i] = d[i] : b[i] = b[i];
    }
    for(i = 1;i <= n;i++) {        
        for(j = i;j <= n;j++) {
            G[i][j] = G[i][j] ^ G[j][i];
            G[j][i] = G[i][j] ^ G[j][i];
            G[i][j] = G[i][j] ^ G[j][i];
        }
    }
    dijkstra(n,x);
    for(i = 1;i <= n;i++) {
        d[i] != inf ? b[i] += d[i] : b[i] = b[i];
    }
    printf("%d\n", findMax(n));
    return 0;
}
