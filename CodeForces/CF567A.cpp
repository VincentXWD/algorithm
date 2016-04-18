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

const int maxn = 1555555;
int n;
int x[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
		}
		sort(x+1,x+n+1);
		printf("%d %d\n", abs(x[1]-x[2]), abs(x[1]-x[n]));
		for(int i = 2; i < n; i++) {
			printf("%d %d\n", abs(x[i]-x[i-1]<abs(x[i]-x[i+1]))?abs(x[i]-x[i-1]):abs(x[i]-x[i+1]),
							   (abs(x[i]-x[n])>abs(x[i]-x[1]))?abs(x[i]-x[n]):abs(x[i]-x[1]));
		}
		printf("%d %d\n", abs(x[n]-x[n-1]), abs(x[1]-x[n]));
	}
	return 0;
}
