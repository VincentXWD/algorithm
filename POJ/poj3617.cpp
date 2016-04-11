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

const int maxn = 2222;
char s[maxn];
char t[maxn];
int n;

int main() {
	// freopen("in", "r", stdin);
	char tmp[3];
	while(~scanf("%d", &n)) {
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", tmp);
			s[cnt++] = tmp[0];
		}
		int b = 0;
		int k = 0;
		cnt = 0;
		n--;
		while(b <= n) {
			int flag = 0;
			for(int i = 0; b + i <= n; i++) {
				if(s[b+i] < s[n-i]) {
					flag = 1;
					break;
				}
				if(s[b+i] > s[n-i]) break;
			}
			cnt++;
			if(flag) putchar(s[b++]);
			else putchar(s[n--]);
			if(cnt % 80 == 0) printf("\n");
		}
	}
	return 0;
}
