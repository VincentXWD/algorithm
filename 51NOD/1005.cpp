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

const int maxn = 11111;
char ca[maxn], cb[maxn], cs[maxn];

void add(char* ca, char* cb) {
	int a[maxn];
	int b[maxn];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	int la = strlen(ca);
	int lb = strlen(cb);
	for(int i = 0; i < la; i++) a[i] = ca[la-i-1] - '0';
	for(int i = 0; i < lb; i++) b[i] = cb[lb-i-1] - '0';
	for(int i = 0; i < maxn; i++) {
        a[i] += b[i];
        a[i+1] += a[i] / 10;
        a[i] %= 10;
	}
	int p = maxn;
	while(p--) if(a[p] != 0) break;
	for(int i = p; i >= 0; i--) printf("%d", a[i]);
	printf("\n");
}

void sub(char* ca, char* cb) {
	int a[maxn];
	int b[maxn];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	int la = strlen(ca);
	int lb = strlen(cb);
	for(int i = 0; i < la; i++) a[i] = ca[la-i-1] - '0';
	for(int i = 0; i < lb; i++) b[i] = cb[lb-i-1] - '0';
	for(int i = 0; i < la; i++) {
		if(a[i] >= b[i]) a[i] -= b[i];
		else {
			a[i] = a[i] - b[i] + 10;
			a[i+1]--;
		}
	}
	int p = maxn;
	while(p--) if(a[p] != 0) break;
	for(int i = p; i >= 0; i--) printf("%d", a[i]);
	printf("\n");
}

int main() {
	// freopen("in", "r", stdin);
	memset(ca, 0, sizeof(ca));
	memset(cb, 0, sizeof(cb));
	scanf("%s %s", ca, cb);
	int la = strlen(ca);
	int lb = strlen(cb);
	if(ca[0] == '0' && cb[0] == '0') printf("0\n");
	else if(ca[0] == '-' && cb[0] == '-') {
		printf("-");
		add(ca+1, cb+1);
	}
	else if(ca[0] != '-' && cb[0] != '-') add(ca, cb);
	else if(ca[0] == '-' && cb[0] != '-') {
		if(la - 1 < lb) sub(cb, ca+1);
		else if(strcmp(ca+1, cb) > 0) {
			printf("-");
			sub(ca+1, cb);
		}
		else if(strcmp(ca+1, cb) == 0) printf("0\n");
		else sub(cb, ca+1);
	}
	else if(ca[0] != '-' && cb[0] == '-') {
		if(la - 1 < lb) sub(ca, cb+1);
		else if(strcmp(ca, cb+1) > 0) sub(ca, cb+1);
		else if(strcmp(ca, cb+1) == 0) printf("0\n");
		else {
			printf("-");
			sub(cb+1, ca);
		}
	}
	return 0;
}
