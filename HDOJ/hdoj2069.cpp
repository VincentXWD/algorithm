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

const int maxn = 255;
int n;
int a[6] = {50, 25, 10, 5, 1};
int dp[maxn][maxn];

int main() {
    // freopen("in", "r", stdin);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < 5; i++) {
    	for(int j = 0; j < maxn; j++) {
    		for(int k = 0; k < 100; k++) {
    			if(a[i] + j <= 250) dp[a[i]+j][k+1] += dp[j][k];
    			else break;
    		}
    	}
    }
    while(~scanf("%d", &n)) {
    	int ans = 0;
    	for(int i = 0; i <= 100; i++) {
    		ans += dp[n][i];
    	}
    	printf("%d\n", ans);
    }
    return 0;
}