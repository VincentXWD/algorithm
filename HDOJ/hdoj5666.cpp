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

//kirai
typedef long long ll;

int T;
ll p, q, x, y, ans;
ll solve(ll a,ll b,ll c) {
	return (a*b-(long long)(a/(long double)c*b+1e-3)*c+c)%c;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d",&T);
	while (T--) {
		scanf("%I64d %I64d",&p,&q);
		x = p - 1;
		y = p - 2;
		if(x % 2 == 0) x /= 2;
		else y /= 2;
		x %= q;
		y %= q;
		ans = solve(x, y, q);
		printf("%I64d\n", ans);
	}
	return 0;
}