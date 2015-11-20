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

int n;
int ans, tmp;

int main() {
	// freopen("in", "r", stdin);
	char cmd[3];
	while(~scanf("%d", &n)) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", &cmd);
			if(cmd[0] == 'C') {
				scanf("%d", &tmp);
				if(tmp == 1) ans++;
			}
			else if(cmd[0] == 'B') {
				scanf("%d", &tmp);
				if(tmp == 1) ans++;
			}
			else ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}