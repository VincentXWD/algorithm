#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int n;
double l[maxn];
long long s;

int main() {
    while(~scanf("%d", &n)) {
        s = 0;
        double ave = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lld", &l[i]);
            ave += l[i];
        }
        ave = (ave) / n;
        for(int i = 0; i < n; i++) {
            if(l[i] > ave) {
                s++;
            }
        }
        printf("%I64d\n", s);
    }
    return 0;
}
