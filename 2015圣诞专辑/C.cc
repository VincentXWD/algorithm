#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

#define pr(x) cout <<#x << " = " << x << endl

using namespace std;

const int maxn = 111111;
const int mod = 10007;

int n;
int a[maxn];
int b[maxn];

int work(int x) {
    return ((1890*x)%mod+143)%mod;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        int ans=0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = work(a[i]) - a[i];
            ans += a[i];
        }
        int sum = 0;
        int cur = 0;    
        for(int i = 0; i < n; i++) {
            if(sum <= 0) {
                sum = b[i];
            }
            else {
                sum += b[i];
            }
            cur = max(sum, cur);
        }
        printf("%d\n", cur + ans);
    }
    return 0;
}