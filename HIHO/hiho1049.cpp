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

const int maxn = 1111;
int n;
char a[maxn], b[maxn];

void dfs(int ll, int rr, int nn) {
	if(nn == 1) {
		printf("%c", a[ll]);
		return;
	}
	if(nn <= 0) return;
	int i;
	for(i = 0; a[ll] != b[rr+i]; i++);
	dfs(ll+1, rr, i);
	dfs(ll+i+1, rr+i+1, nn-i-1);
	printf("%c", a[ll]);
}
int main() {
	// freopen("in", "r", stdin);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%s", a);
	scanf("%s", b);
	n = strlen(a);
	for(int i = n; i >= 0; i--) {
		a[i] = a[i-1];
		b[i] = b[i-1];
	}
	dfs(1, 1, n);
	printf("\n");
}