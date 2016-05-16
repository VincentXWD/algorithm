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

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Fread() freopen("in", "r", stdin)
#define Fwrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), (0), sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

typedef long long LL;
const int maxn = 500010;
int n;
int num[maxn];
int ll[maxn>>1], rr[maxn>>1];
LL ans;

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
	// Fread();
	while(~Rint(n) && n) {
		ans = 0;
		Rep(i, n) Rint(num[i]);
		mergesort(num, 0, n-1);
		printf("%I64d\n", ans);
	}
	return 0;
}
