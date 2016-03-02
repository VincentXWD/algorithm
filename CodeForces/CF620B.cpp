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

const int seg[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int a, b;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &a, &b)) {
		int ans = 0;
		for(int i = a; i <= b; i++) {
			int tmp = i;
			while(tmp) {
				ans += seg[tmp%10];
				tmp /= 10;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}