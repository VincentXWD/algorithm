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
int c1[maxn], c2[maxn];
int n;

void mother_function() {
	for(int i = 0; i <= n; i++) {
		c1[i] = 1; c2[i] = 0;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k + j <= n; k+=i) {
				c2[j+k] += c1[j];
			}
		}
		for(int j = 0; j <= n; j++) {
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		mother_function();
		printf("%d\n", c1[n]);
	}
	return 0;
}
