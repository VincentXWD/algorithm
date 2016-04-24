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

int ex, ey;

int main() {
	// freopen("in", "r", stdin);
	int T, _ = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &ex, &ey);
		int k = __gcd(ex, ey);
		if(ex < ey) swap(ex, ey);
		int ans = 1;
		while(ex % (ey + k) == 0) {
			ans++;
			ex = ex / (ey / k + 1);	//m1*k/(m2+1)
			if(ex < ey) swap(ex, ey);
			k = __gcd(ex, ey);
			// cout << ex <<" " << ey << endl;
		}
		printf("Case #%d: %d\n", _++, ans);
	}
	return 0;
}