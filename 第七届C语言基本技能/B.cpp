#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 111;
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}
char G[maxn][maxn];

int check() {
    int a = 0;
    int b = 0;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(G[i][j] == 'A' && G[i][j+1] == 'A' && G[i][j+2]  == 'A' && G[i][j+3]  == 'A' && G[i][j+4] == 'A') a = 1;
            if(G[i][j] == 'B' && G[i][j+1] == 'B' && G[i][j+2]  == 'B' && G[i][j+3]  == 'B' && G[i][j+4] == 'B') b = 1;
            if(G[j][i] == 'A' && G[j+1][i] == 'A' && G[j+2][i] == 'A' && G[j+3][i] == 'A' && G[j+4][i] == 'A') a = 1;
            if(G[j][i] == 'B' && G[j+1][i] == 'B' && G[j+2][i] == 'B' && G[j+3][i] == 'B' && G[j+4][i] == 'B') b = 1;
            if(G[i][j] == 'A' && G[i-1][j+1] == 'A' && G[i-2][j+2] == 'A' && G[i-3][j+3] == 'A' && G[i-4][j+4] == 'A') a = 1;
            if(G[i][j] == 'B' && G[i-1][j+1] == 'B' && G[i-2][j+2] == 'B' && G[i-3][j+3] == 'B' && G[i-4][j+4] == 'B') b = 1;
            if(G[i][j] == 'A' && G[i-1][j-1] == 'A' && G[i-2][j-2] == 'A' && G[i-3][j-3] == 'A' && G[i-4][j-4] == 'A') a = 1;
            if(G[i][j] == 'B' && G[i-1][j-1] == 'B' && G[i-2][j-2] == 'B' && G[i-3][j-3] == 'B' && G[i-4][j-4] == 'B') b = 1;
            if(G[i][j] == 'A' && G[i+1][j-1] == 'A' && G[i+2][j-2] == 'A' && G[i+3][j-3] == 'A' && G[i+4][j-4] == 'A') a = 1;
            if(G[i][j] == 'B' && G[i+1][j-1] == 'B' && G[i+2][j-2] == 'B' && G[i+3][j-3] == 'B' && G[i+4][j-4] == 'B') b = 1;
        }
    }
    if(a == 1 && b == 0) return 1;
    if(a == 0 && b == 1) return 2;
    if(a == 0 && b == 0) return 3;
    return 0;
}

int main() {
    //freopen("in","r",stdin);
    int i, j, k;
    memset(G, 0, sizeof(G));
    for(i = 1; i <= 10; i++) scanf("%s", G[i]);
    int flag = check();
    if(flag == 1) printf("A wins!\n");
    else if(flag == 2) printf("B wins!\n");
    else if(flag == 3) printf("No one wins!\n");
    else printf("Error!\n");
    return 0;
}