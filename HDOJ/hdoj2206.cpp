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
char ip[maxn];
int poi[5];
int num[5];
int n, cnt, nc;

//s+1 e-1
int tonum(int s, int e) {
	int tmp = 0;
	int ad = 1;
	for (int i = e - 1; i >= s + 1; i--) {
		tmp += (ip[i] - '0') * ad;
		ad *= 10;
	}
	return tmp;
}

int main() {
	// freopen("in", "r", stdin);
	while(gets(ip)) {
		n = strlen(ip);
		cnt = 0;
		nc = 0;
		poi[cnt++] = -1;
		poi[4] = n;
		int exflag = 0;
		int cma = 0;
		for(int i = 0; i < n; i++) {
			if(ip[i] < '0' || ip[i] > '9') {
				if(ip[i] == '.') {
					cma++;
					if(ip[i-1] >= '0' && ip[i-1] <= '9' &&
					   ip[i+1] >= '0' && ip[i+1] <= '9') {
					   	poi[cnt++] = i;
						continue;
					}
					// kill 1.1.1.
					else {
						exflag = 1;
						break;
					}
				}
				// kill a.1.1.1
				else {
					exflag = 1;
					break;
				}
			}
		}
		// kill .1.1.1.1
		if(cma != 3) exflag = 1;
		if(exflag == 1) {
			printf("NO\n");
			continue;
		}
		for(int i = 0; i < cnt; i++) {
			num[nc++] = tonum(poi[i], poi[i+1]);
			// kill 0003.1.1.1
			if((poi[i+1] - 1) - (poi[i] + 1) + 1 > 3) {
				exflag = 1;
				break;
			}
			// kill 256.1.1.1
			if(num[nc-1] > 0xff) {
				exflag = 1;
				break;
			}
		}
		if(exflag == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}