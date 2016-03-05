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

const int maxn = 1111111;
int a[maxn];
int n;

int main() {
    // freopen("in", "r", stdin);
    int T;
    int ll, rr;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int flag = 0;
        for(int i = 0; i < n - 1; i++) {
            a[i+1] -= a[i];
            if(a[i+1] < 0) {
                flag = 1;
                printf("I will never go out T_T\n");
                break;
            }
        }
        if(!flag) {
            if(a[n-1] == 0) {
                printf("yeah~ I escaped ^_^\n");
            }
            else {
                printf("I will never go out T_T\n");
            }
        }
    }
}