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

const int maxn = 100010;
int n, m, q, x;

int main() {
    // freopen("in", "r", stdin);
    int kase = 0;
    int T_T;
    scanf("%d", &T_T);
    while(T_T--) {
        scanf("%d %d %d", &n, &m, &q);
        printf("Case #%d:\n", ++kase);
        for(int i = 0; i < q; i++) {
            scanf("%d", &x);
            if(x <= n && x < m) {
                printf("%d\n", x-1);
            }
            else if(x > n + m) {
                printf("%d\n", 0);
            }
            else if(x > n && x <= m){
                printf("%d\n", n);
            }
            else if(x <= n && x > m) {
                printf("%d\n", m);
            }
            else if(x > n && x > m) {
                printf("%d\n", n + m - x + 1);
            }
            else {
                printf("%d\n", x - 1);
            }
        }
    }
}
