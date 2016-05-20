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

const int maxn = 11;
double n, V;
double a[maxn], v[maxn];
double ans;

int main() {
	// FRead();
	while(cin >> n >> V) {
		bool exflag = 0;
		ans = 0;
		Rep(i, n) {
			cin >> a[i] >> v[i];
			if(abs(v[i]) >= V && a[i] != 0) exflag = 1;
		}
		if(exflag) {
			printf("Bad Dog\n");
			continue;
		}
		double pos = 0;
		Rep(i, n) {
			a[i] += ans * v[i];
			if(a[i] == pos) continue;
			if(a[i] < pos) V = -1 * abs(V);
			else V = abs(V);
			if(abs(V - v[i]) <= 0) {
				exflag = 1;
				break;
			}
			double d = abs(pos - a[i]);
			double t = d / abs(V - v[i]);
			ans += t;
			pos += t * V;
		}
		if(exflag) printf("Bad Dog\n");		
		else printf("%.2lf\n", ans);
	}
	return 0;
}