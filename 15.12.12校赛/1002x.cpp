/*
注意n,m=0的情况，会不输出结果，而答案应该是YES
*/
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
char a[maxn];
char b[maxn];
int n, m;

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int ans = 0;
        if(n != 0) {        
            scanf("%s", a);
            scanf("%s", b);
        }
        for(int i = 0; i < n; i++) {    //O(n)
            int mi = abs((a[i]-'0')-(b[i]-'0'));
            ans += min(mi, 10-mi);
        }
        if(ans > m) {
        	printf("NO\n");
        }
        else {
        	printf("YES\n");
        }
    }
    return 0;
}
