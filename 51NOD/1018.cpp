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

const int maxn = 50010;
int lo[maxn>>1];
int hi[maxn>>1];
int a[maxn];
int n;

void merge(int* a, int ll, int mm, int rr) {
    int no = mm - ll + 1;
    int ni = rr - mm;
    for(int ii = 0; ii < no; ii++) lo[ii] = a[ll+ii];
    for(int ii = 0; ii < ni; ii++) hi[ii] = a[mm+ii+1];
    int i = 0, j = 0;
    while(i < no && j < ni) {
        if(lo[i] < hi[j]) a[ll++] = lo[i++];
        else a[ll++] = hi[j++];
    }
    while(i < no) a[ll++] = lo[i++];
    while(j < ni) a[ll++] = hi[j++];
}

void mergesort(int* a, int ll, int rr) {
    if(ll < rr) {
        int mm = (ll + rr) >> 1;
        mergesort(a, ll, mm);
        mergesort(a, mm+1, rr);
        merge(a, ll, mm, rr);
    }
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        mergesort(a, 0, n-1);
        for(int i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}