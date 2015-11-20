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

int a, b, c;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &a, &b)) {
		int flag = 0;
		if(sqrt(a*a+b*b) == (int)sqrt(a*a+b*b)) flag = 1;
		if(a > b) {			
			if(sqrt(a*a-b*b) == (int)sqrt(a*a-b*b)) flag = 1;
		}
		else {
			if(sqrt(b*b-a*a) == (int)sqrt(b*b-a*a)) flag = 1;
		}
		if(flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
