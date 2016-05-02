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

const int maxn = 100010;
int num[maxn];
long long ans;
int ll[maxn>>1], rr[maxn>>1];

void merge(int *num, int p, int m, int q) {
    int n1 = m - p + 1;
    int n2 = q - m;
    int i = 0, j = 0;
    for(int ii = 0; ii < n1; ii++) ll[ii] = num[p+ii];
    for(int ii = 0; ii < n2; ii++) rr[ii] = num[m+ii+1];
    while(i < n1 && j < n2) {
        if(ll[i] <= rr[j]) num[p++] = ll[i++];
        else {            
            num[p++] = rr[j++];
            ans += (n1 - i);
        }
    }
    while(i < n1) num[p++] = ll[i++];
    while(j < n2) num[p++] = rr[j++];
}

void mergesort(int *num, int p, int q) {
    if(p < q) {
        int m = (p + q) >> 1;
        mergesort(num, p, m);
        mergesort(num, m+1, q);
        merge(num, p, m, q);
    }
}

int main() {
    // freopen("in", "r", stdin);
    int n;
    while(~scanf("%d", &n)) {
        ans = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
        }
        mergesort(num, 1, n);
        cout << ans << endl;
    }
}
