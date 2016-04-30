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

typedef long long ll;
const int maxn = 11111;
ll n;

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d", &n);
        if(n==1||n==2||n==4) {
            printf("False\n");
            continue;
        }
        if(n % 2 == 1) {
            printf("True\n");
            continue;
        }
        else {
            if(n % 4 == 0) {
                printf("True\n");
                continue;
            }
            if(n & 1) {
                printf("True\n");
                continue;
            }
        }
        printf("False\n");
    }
    return 0;
}