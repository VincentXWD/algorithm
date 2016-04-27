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

const int maxn = 1010;
const double eps = 1e-8;
int n;
double m;
int v[maxn];
double w[maxn];
double dp[1000010];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		cin >> m >> n;
		m = 1 - m;
		int mm = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++) {
			cin >> v[i] >> w[i];
			w[i] = 1 - w[i];
			mm += v[i];
		}
		dp[0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = mm; j >= v[i]; j--) {
				dp[j] = max(dp[j], dp[j-v[i]]*w[i]);
			}
		}
		for(int i = mm; i >= 0; i--) {
			if(dp[i] - m > eps) {
				printf("%d\n", i);
				break;
			}
		}
 	}
	return 0;
}