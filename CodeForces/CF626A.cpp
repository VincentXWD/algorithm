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

const int maxn = 555555;
int n;
char str[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		scanf("%s", str);
		int ans = 0;
		int u, d, l, r;
		for(int i = 0; str[i]; i++) {
			u = d = l = r = 0;
			for(int j = i; str[j]; j++) {
				if(str[j] == 'U') u++;
				if(str[j] == 'D') d++;
				if(str[j] == 'L') l++;
				if(str[j] == 'R') r++;
				if(l == r && u == d) {
					for(int k = i; k <= j; k++) {
						printf("%c", str[k]);
					}
					printf("\n");
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
