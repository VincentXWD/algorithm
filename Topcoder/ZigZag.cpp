#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

class ZigZag {
public:
	int longestZigZag(vector<int> sequence) {
		int dp[101010][2];
		int n = sequence.size();
		int a[101010];
		int ret = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) a[i] = sequence[i-1];
		for(int i = 1; i <= n; i++) {
			dp[i][0] = dp[i][1] = 1;
			for(int k = 0; k < 2; k++) {
				for(int j = 1; j <= i; j++) {
					if(a[i] == a[j]) continue;
					if(k == 0) {
						if(a[i] < a[j])	dp[i][k] = max(dp[i][k], dp[j][!k]+1);
					}
					else {
						if(a[i] > a[j])	dp[i][k] = max(dp[i][k], dp[j][!k]+1);
					}
				}
				ret = max(ret, max(dp[i][0], dp[i][1]));
			}
		}
		return ret;
	}
};
