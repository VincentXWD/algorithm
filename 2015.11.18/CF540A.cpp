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

const int maxn = 1111;
char a[maxn];
char b[maxn];
int n;

int main() {
    // freopen("in", "r", stdin);
    int ans = 0;
    scanf("%d %s %s", &n, a, b);
    for(int i = 0; i < n; i++) {
        int mi = abs((a[i]-'0')-(b[i]-'0'));
        ans += (min(mi, 10-mi));
    }
    printf("%d\n", ans);
    return 0;
}
