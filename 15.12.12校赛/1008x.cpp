/*
数学推导即可
*/
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

typedef long long int LL;

LL solve(LL x) {
	if(x == 1) return 1;
	if(x & 1) return solve(x / 2) * 3 + 1;
	return solve(x / 2) * 3;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		LL n;
		scanf("%I64d", &n);
		printf("%I64d\n", solve(n));
	}
}
