#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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

typedef long long LL;
const int mod = 1000;

LL quickmul(int x, int n) {
    LL ans = 1;
    LL t = x;
    while(n) {
        if(n & 1) {
            ans = (ans * t);
        }
        t = t * t;
        n >>= 1;
    }
    return ans;
}

int n;

int main() {
    while(~scanf("%d", &n)) {
        printf("%I64d\n", quickmul(2, n+1)-2);
    }
    return 0;
}