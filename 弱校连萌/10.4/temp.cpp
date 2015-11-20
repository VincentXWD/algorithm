#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n;

void output1(int cnt, int n) {
	if(cnt >= 26) {
		for(int i = 0; i < n; i++) {
			printf("%c", cnt - 26 + 'A');
		}
	}
	else {
		for(int i = 0; i < n; i++) {
			printf("%c", cnt + 'a');
		}
	}
}

void output2(int n) {
	if(n > 26) {
		for(int i = 0; i < 26; i++) {
			printf("%c", i + 'a');
		}
		for(int i = 0; i < n-26; i++) {
			printf("%c", i + 'A');
		}
	}
	else {
		for(int i = 0; i < n; i++) {
			printf("%c", i + 'a');
		}
	}
	printf("\n");
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		printf("%d %d %d\n", n, n, 2);
		for(int i = 0; i < n; i++) {
			output1(i, n);
			printf("\n");
			output2(n);
			printf("\n");
		}
	}
}
