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

typedef unsigned long long ULL;
const int maxn = 13;
ULL po[maxn] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int but[10];
int n;
int num[maxn];


int main() {
    while(~scanf("%d", &n) && n) {
        int flag = 0;
        ULL sum = 0;
        memset(num, 0, sizeof(num));
        memset(but, 0, sizeof(but));
        for(int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            sum += num[i];
            but[num[i]]++;
        }
        sort(num, num+n);
        ULL poi = po[n];
        for(int i = 0; i <= 9; i++) {
            if(but[i] == n) {
                flag = 1;
                break;
            }
            if(but[i] != 0) {
                poi /= po[but[i]];
            }
        }
        if(flag) {            
            for(int i = 0; i < n; i++) {
                printf("%d", num[0]);
                if(num[0] == 0) break;
            }
            printf("\n");
        }
        else {
            ULL ans = 0;
            sum = sum * poi / n;
            for(int i = 0; i < n; i++) {
                ans += sum;
                sum *= 10;
            }
            printf("%llu\n", ans);
        }
    }
    return 0;
}