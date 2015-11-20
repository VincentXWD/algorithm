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
char s[maxn], tmp[maxn];
int m;

int main() {
    // freopen("in", "r", stdin);
    int T;
    memset(s, 0, sizeof(s));
    scanf("%s", s);
    scanf("%d", &T);
    while(T--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        --l, --r;
        int len = r - l + 1;
        int kk = k % len;
        strcpy(tmp, s);
        for(int i = l; i <= r; i++) {
            s[i] = tmp[l+((i-l)-kk+len)%len];
        }
    }
    printf("%s\n", s);
    return 0;
}
