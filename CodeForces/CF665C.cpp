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

const int maxn = 200010;
char s[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%s", s)) {
		int n = strlen(s);
		for(int i = 0; i < n; i++) {
			if(s[i] == s[i] + 1 || s[i] == s[i-1]) {
				for(char j = 'a'; j <= 'z'; j++) {
					if(s[i] != j && s[i+1] != j && s[i-1] != j) {
						s[i] = j;
					}
				}
			}
		}
		printf("%s\n", s);
	}
	return 0;
}