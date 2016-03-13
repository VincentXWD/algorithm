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

bool cmp(string a, string b) {
	return a + b < b + a;
}

const int maxn = 55555;
int n;
string a[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		for(int i = 0; i < n; i++) {
			cout << a[i];
		}
		puts("");
	}
	return 0;
}