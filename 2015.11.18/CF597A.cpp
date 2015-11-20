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

long long a, b, k;

int main() {
	// freopen("in", "r", stdin);
	// int T;
	// scanf("%d", &T);
	while(~scanf("%I64d %I64d %I64d", &k, &a, &b)) {
        long long c;
        c = abs(a) + 2;
        c = (c / k + 1) * k;
        printf("%I64d\n", (b + c) / k - (a + c - 1) / k);
    }
    return 0;
}
