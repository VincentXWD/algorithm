#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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

typedef long long LL;
typedef struct P {
	LL x;
	LL y;
}P;

P a, b;

int main() {
	while(cin >> a.x >> a.y >> b.x >> b.y) {
		LL ans = 0;
		if(!((b.y - a.y) & 1)) {
			ans += (b.y - a.y) / 2 * (b.x - a.x) / 2;
			ans += (b.y - a.y + 2) / 2 * (b.x - a.x + 2) / 2;
		}
		else {
			ans += (b.y - a.y + 1) / 2 * (b.x - a.x + 1) / 2;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}