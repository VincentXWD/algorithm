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
int na, nb;
char a[maxn];
char b[maxn];
int pre[maxn];

void getpre(char *b, int *pre) {
    int j, k;
    pre[0] = -1;
    j = 0;
    k = -1;
    while(j < nb) {
        if(k == -1 || b[j] == b[k]) {
            pre[++j] = ++k;
            if(b[j] != b[k]) pre[j] = k;
            else pre[j] = pre[k];
        }
        else k = pre[k];
    }
}

int kmp() {
    int ans = 0;
    int i = 0;
    int j = 0;
    getpre(b, pre);
    while(i < na) {
        if(j == -1 || a[i] == b[j]) i++, j++;
        else j = pre[j];
        if(j == nb) ans++;
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(pre, 0, sizeof(pre));
        scanf("%s %s", b, a);
        na = strlen(a);
        nb = strlen(b);
        printf("%d\n", kmp());
    }
    return 0;
}