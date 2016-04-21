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

const int maxn = 222;
int a, ta, b, tb;
int hh, mm;
char str[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d%d%d", &a, &ta, &b, &tb)) {
		scanf("%d:%d", &hh, &mm);
		mm += (hh - 5) * 60;
		int ed = mm + ta;
		int ans = 0;
		for(int i = 0; i <= 1139; i+=b) {
			if(i + tb > mm && i < ed) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}