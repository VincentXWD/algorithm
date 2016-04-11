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

typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll> > pq;
int n;

int main() {
	// freopen("in", "r", stdin);
	ll tmp;
	while(~scanf("%d", &n)) {
		while(!pq.empty()) pq.pop();
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			pq.push(tmp);
		}
		ll ans = 0;

		while(n-- > 1) {
			tmp = pq.top(); pq.pop();
			tmp += pq.top(); pq.pop();
			pq.push(tmp);
			ans += tmp;
		}
		cout << ans << endl;
	}
	return 0;
}
