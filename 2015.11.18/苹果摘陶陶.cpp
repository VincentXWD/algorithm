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

const int maxn = 2222;
const int inf = 111111;
int n, m, cnt;
int pg[maxn], tt[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &pg[i]);
	for(int i = 0; i < m; i++) scanf("%d", &tt[i]);
	cnt = m;
	for(int i = 0; i < n; i++) {
		int cur = 0, id;
		for(int j = 0; j < m; j++) {
			if(pg[i] > tt[j] && tt[j] > cur) {
				cur = tt[j];
				id = j;
			}
		}
		if(cur) {
			tt[id] = inf;
			cnt--;
		}
	}
	printf("%d\n", cnt);
	return 0;
}