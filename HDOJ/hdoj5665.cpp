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

//kirai
const int maxn = 11111;
int a[maxn];
int n;

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        bool ok1 = 0;
        bool ok2 = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if(a[i] == 1) ok1 = 1;
            if(a[i] == 0) ok2 = 1;
        }
        if(ok1 == 1 && ok2 == 1) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}