#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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

int n;

int main() {
	while(~scanf("%d", &n)) {
		if(n & 1) {
			printf("1\n");
		}
		else {
			printf("2\n");
		}
	}
}