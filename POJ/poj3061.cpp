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
int n, s;
int x[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &s);
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
			sum += x[i];
		}
		if(sum < s) {
			printf("0\n");
			continue;
		}
		int ans = 0x7f7f7f;
		int ll = 1;
		int rr = 1;
		sum = 0;
		while(1) {
			while(rr <= n && sum <= s) {
				sum += x[rr++];
			}
			if(sum < s) break;
			ans = min(ans, rr-ll);
			sum -= x[ll++];
		}
		printf("%d\n", ans);
	}
}