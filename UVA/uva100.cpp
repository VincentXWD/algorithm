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
int n, m;

int count(int x) {
	int cnt = 1;
	while (x != 1) {
		if (x % 2 == 1) x = 3 * x + 1;
		else x = x / 2;
		cnt++;
	}
	return cnt;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		int ans = 0;
		int a, b;
		if(n > m) a = m, b = n;
		else a = n, b = m;
		for(int i = a; i <= b; i++) {
			ans = max(ans, count(i));
		}
		printf("%d %d %d\n", n, m, ans);
	}
	return 0;
}
