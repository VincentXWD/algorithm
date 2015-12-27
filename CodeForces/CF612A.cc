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

const int maxn = 111;
int n, p, q;
char str[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d %d", &n, &p, &q)) {
		scanf("%s", str);
		int flag = 0;
		int x = n / p, y = n / q;
		for(int i = 0; i <= x; i++) {
			if(flag) break;
			for(int j = 0; j <= y; j++) {
				if(flag) break;
				if(n == i * p + j * q) {
					flag = 1;
					printf("%d\n", i + j);
					for(int k = 1; k <= i * p; k++) {
						printf("%c", str[k-1]);
						if(k % p == 0) {
							printf("\n");
						}
					}
					for(int k = i * p + 1; k <= n; k++) {
						printf("%c", str[k-1]);
						if((k - i * p) % q == 0) {
							printf("\n");
						}
					}
				}
			}
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}