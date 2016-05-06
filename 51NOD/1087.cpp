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

typedef long long LL;
LL n;

LL f(LL n) {
	return (n * n - n) / 2 + 1;
}

int main() {
	freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%I64d", &n);
		bool flag = 0;
		LL ll = 0, rr = n;
		while(ll <= rr) {
			LL mm = (ll + rr) >> 1;
			LL val = f(mm);
			if(val == n) {
				flag = 1;
				break;
			}
			else if(val > n) rr = mm - 1;
			else ll = mm + 1;
		}
		printf("%d\n", flag);
	}
	return 0;
}