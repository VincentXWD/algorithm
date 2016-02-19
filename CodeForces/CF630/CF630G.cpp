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

LL C(LL n, LL m) {
	if(m > n) {
		return 0;
	}
	LL ans = 1;
	for(int i = 1; i <= m; i++) {
		ans = ans * (n - i + 1) / i;
	}
	return ans;
}

LL n;

int main() {
	while(~scanf("%I64d", &n)) {
		printf("%I64d\n", C(n+4, 5)*C(n+2, 3));
	}
	return 0;
}