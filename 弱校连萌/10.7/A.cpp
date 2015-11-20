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

int a[3];

int main() {
    // freopen("in", "r", stdin);
    int kase = 0;
    int T_T;
    scanf("%d", &T_T);
    while(T_T--) {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        printf("Case #%d:\n", ++kase);
        sort(a, a+3);
        if(a[0] == a[2]) {
            printf("%d %d %d\n", a[0], a[0], a[0]);
        }
        else if(a[0] == a[1]) {
            printf("%d %d %d\n", a[0], a[1], a[2]);
            printf("%d %d %d\n", a[1], a[2], a[0]);
            printf("%d %d %d\n", a[2], a[1], a[0]);
        }
        else if(a[1] == a[2]) {
            printf("%d %d %d\n", a[0], a[1], a[2]);
            printf("%d %d %d\n", a[1], a[0], a[2]);
            printf("%d %d %d\n", a[2], a[1], a[0]);
        }
        else {
            printf("%d %d %d\n", a[0], a[1], a[2]);
            printf("%d %d %d\n", a[0], a[2], a[1]);
            printf("%d %d %d\n", a[1], a[0], a[2]);
            printf("%d %d %d\n", a[1], a[2], a[0]);
            printf("%d %d %d\n", a[2], a[0], a[1]);
            printf("%d %d %d\n", a[2], a[1], a[0]);
        }
    }
}
