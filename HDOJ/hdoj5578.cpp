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

const int maxn = 1010;
const int inf = 0x7f7f7f7f;
char str[maxn];
int pos[257], ans;

int main() {
    // freopen("in", "r", stdin);
    int T, _ = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        ans = inf;
        memset(pos, -1, sizeof(pos));
        for(int i = 0; str[i]; i++) {
            if(~pos[str[i]])
                ans = min(ans, i-pos[str[i]]);
            pos[str[i]] = i;
        }
        printf("Case #%d: %d\n", _++, ans == inf ? -1 : ans);
    }
    return 0;
}
