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

typedef unsigned long long ull;
ull a[5];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int flag = 1;
		for(int i = 0; i < 4; i++) {
			cin >> a[i];
			if(a[i] == 0) flag = 0;
		}
		sort(a, a+4);
		if(a[0] + a[1] > a[3] - a[2] && flag) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}