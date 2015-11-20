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

typedef struct P {
	int x;
	int y;
};

int n;
P p[5];

int main() {
	// freopen("in", "r", stdin);
	// while(~scanf("%d", &n)) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		int flag = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(p[i].x != p[j].x && p[i].y != p[j].y) {
					flag = 1;
					printf("%d\n", abs(p[i].x-p[j].x)*abs(p[i].y-p[j].y));
					break;
				}
			}
			if(flag) {
				break;
			}
		}
		if(!flag) {
			printf("-1\n");
		}
	// }
}
