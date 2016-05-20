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
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

typedef long long ll;
const int maxn = 33;
string s;
int g[3];

int main() {
	// FRead();
	int T;
	Rint(T);
	while(T--) {
		string pre;
		int pos = 0;
		Cls(g);
		while(cin >> s) {
			if(s[0] == 'E') break;
			if(::s == pre) {
				pos = 1 - pos;
				g[pos]++;
				pre = ::s;
			}
			else {
				g[pos]++;
				pre = ::s;
			}
		}
		// cout << g[0] <<  " "<< g[1] <<endl;
		printf("%d\n", g[0] * g[1]);
	}
	return 0;
}