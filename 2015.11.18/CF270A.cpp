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

int main() {
    // freopen("in", "r", stdin);
    int T;
    int n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(!(360 % (180 - n))) printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}