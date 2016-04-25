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
const int maxn = 66;

ll n, k;
ll path[maxn][3];
int pcnt;
//1 + 0 -
bool exflag;
void dfs(ll cur, ll lv, ll id) {
    if(exflag) return;
    if(cur == n && lv == k) {
        for(ll i = 0; i < pcnt; i++) {
            printf("%I64d %c\n", path[i][0], path[i][1] == 1 ? '+' : '-');
        }
        exflag = 1;
        return;
    }
    if(cur != n && lv == k) return;

    path[pcnt][0] = id;
    path[pcnt++][1] = 1;
    dfs(cur+id ,lv+1, id*2);
    pcnt--;

    path[pcnt][0] = id;
    path[pcnt++][1] = 1;
    dfs(cur+id ,lv+1, id*2+1);
    pcnt--;

    path[pcnt][0] = id;
    path[pcnt++][1] = 0;
    dfs(cur-id ,lv+1, id*2);
    pcnt--;

    path[pcnt][0] = id;
    path[pcnt++][1] = 0;
    dfs(cur-id ,lv+1, id*2+1);
    pcnt--;
}

int main() {
    freopen("in", "r", stdin);
    int T, _ = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d %I64d", &n, &k);
        pcnt = 0; exflag = 0;
        printf("Case #%d:\n", _++);
        dfs(0, 0, 1);
    }
    return 0;
}
