#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int score[maxn], trait[maxn];
int n, k;

int main() {
	// freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &k)) {	
	    int y, f;
	    memset(trait, 0, sizeof(trait));
	    for(int i = 0; i < n; i++) {
	        scanf("%d %d", &score[i], &y);
	        for(int j = 0; j < y; j++) {
	            scanf("%d", &f);
	            trait[i] += (1 << f);
	        }
	    }
	    int m;
	    scanf("%d", &m);
	    while(m--) {
	        int t, a, h;
	        int cur = 0, ans = 1;
	        scanf("%d %d", &a, &t);
	        a--;
	        for(int i = 0; i < t; i++) {
	            scanf("%d", &h);
	            cur += (1 << h);
	        }
	        for(int i = 0; i < n; i++) {
	            if((trait[i] & cur) == (trait[a] & cur) && score[i] > score[a]) {
	                ans++;
	            }
	        }
	        printf("%d\n", ans);
	    }
    }
}
