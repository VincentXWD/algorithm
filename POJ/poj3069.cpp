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
int r, n; 
int a[maxn];
int cnt;
int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &r, &n) && r + n != -2) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		cnt = 0;
		int i = 0;
		while(i < n) {
			int p = a[i++];
			while(i < n && a[i] <= p + r) i++;
			int q = a[i-1];
			while(i < n && a[i] <= q + r) i++;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
