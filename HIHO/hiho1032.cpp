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

const int maxn = 1111111;
int pre[maxn<<2];
char x[maxn];
char str[maxn<<2];

inline int min(int x, int y) {
    return x < y ? x : y;
}

int init(char *str, char *x) {
    int len = strlen(x);
    str[0] = '$';
    for(int i = 0; i <= len; i++) {
        str[2*i+1] = '#';
        str[2*i+2] = x[i];
    }
    len = 2 * len + 2;
    str[len] = 0;
    return len;
}
void manacher(int *pre, char *str, int len) {
    int id = 0;
    int mx = 0;
    for(int i = 1; i < len; i++) {
        pre[i] = mx > i ? min(pre[2*id-i], mx-i) : 1;
        while(str[i+pre[i]] == str[i-pre[i]]) pre[i]++;
        if(pre[i] + i > mx) {
            id = i;
            mx = pre[id] + id;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", x);
        memset(pre, 0, sizeof(pre));
        memset(str, 0, sizeof(str));
        int len = init(str, x);
        manacher(pre, str, len);
        int ans = 1;
        for(int i = 0; i < len; i++) {
            ans = max(ans, pre[i]);
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
