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

LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a%b);
}

LL n;

int main() {
	while(~scanf("%I64d", &n)) {
		LL t = 1;
		for(int i = 1; i <= 10; i++) {
			t = t / gcd(i, t) * i;
		}
		printf("%I64d\n", n / t);
	}
	return 0;
}