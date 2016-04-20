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

const int maxn = 11111;
char ca[maxn], cb[maxn], cs[maxn];
void add(char* ca, char* cb, char* cs) {
    int a[maxn];
    int b[maxn];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(cs, 0, sizeof(cs));
    int la = strlen(ca);
    int lb = strlen(cb);
    for(int i = 0; i < la; i++) a[i] = ca[la-i-1] - '0';
    for(int i = 0; i < lb; i++) b[i] = cb[lb-i-1] - '0';
    for(int i = 0; i < maxn; i++) {
        a[i] += b[i];
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    int p = maxn - 1;
    while(p >= 1 && !a[p]) p--;
    while(p >= 0) printf("%d", a[p--]);
}

void multi(char* ca, char* cb, char* cs) {
    int s[maxn];
    memset(s, 0, sizeof(s));
    memset(cs, 0, sizeof(cs));
    int la = strlen(ca), lb = strlen(cb);
    for(int i = 0; i < la; i++) {
        for(int j = 0; j < lb; j++) {
            s[i+j+1] += (ca[i] - '0') * (cb[j] - '0');
        }
    }
    for(int i = la + lb - 1; i >= 0; i--) {
        s[i-1] += s[i] / 10;
        s[i] %= 10;
    }
    int p = 0;
    while(s[p] == 0) p++;
    for(int i = 0; p < la + lb; i++, p++) {
        cs[i] = s[p] + '0';
    }
}

int main() {
    // freopen("in", "r", stdin);
    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));
    scanf("%s %s", ca, cb);
    multi(ca, cb, cs);
    printf("%s\n", cs);
    return 0;
}