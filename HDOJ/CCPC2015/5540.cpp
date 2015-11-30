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

int x[4];
int y[4];

int main() {
    // freopen("in", "r", stdin);
    int T;
    int n;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++) {
        for(int i = 0; i < 4; i++) scanf("%d", &x[i]);
        for(int i = 0; i < 4; i++) scanf("%d", &y[i]);
        int flag = 0;
        if(x[0] == y[0] && x[1] == y[1] && x[2] == y[2] && x[3] == y[3]) flag = true;
        else if(x[0] == y[1] && x[1 ]== y[3] && x[2] == y[0] && x[3] == y[2]) flag = true;
        else if(x[0] == y[2] && x[1 ]== y[0] && x[2] == y[3] && x[3] == y[1]) flag = true;
        else if(x[0] == y[3] && x[1 ]== y[2] && x[2] == y[1] && x[3] == y[0]) flag = true;

        printf("Case #%d: ", _);
        if(flag) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
}