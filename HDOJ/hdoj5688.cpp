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

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 51;
int n;
char s[maxn];
map<string, int> vis;
map<string, int>::iterator it;

int main() {
	// FRead();
	while(~Rint(n)) {
		vis.clear();
		Rep(i, n) {
			Rs(s);
			int len = strlen(s);
			sort(s, s+len);
			it = vis.find(s);
			if(it == vis.end()) {
				vis[s] = 1;
				printf("%d\n", 0);
				continue;
			}
			printf("%d\n", vis[s]);
			vis[s]++;
		}
	}
	return 0;
}