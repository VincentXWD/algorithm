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

const int maxn = 444;
int n, m;

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        stack<int> st[maxn];
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            st[i%(2*n)].push(++cnt);
        }
        printf("%d", st[0].top());
        st[0].pop();
        for(int i = 0; i < 2 * n; i++) {
            while(!st[i].empty()) {
                printf(" %d", st[i].top());
                st[i].pop();
            }
        }
        printf("\n");
    }
    return 0;
}