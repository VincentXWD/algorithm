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

const int maxn = 111111;
char tmp[maxn];
int s[maxn], b[maxn];

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%s", tmp) && strcmp("0", tmp)) {
        int tlen = strlen(tmp);
        memset(b, 0, sizeof(b));
        for(int i = 0; i < tlen; i++) {
        	b[i] = tmp[tlen-i-1] - '0';
        }
        for(int i = 0; i < maxn; i++) {
        	s[i] += b[i];
        	s[i+1] += s[i] / 10;
        	s[i] %= 10;
        }
    }
    int p = maxn;
    while(p >= 1 && !s[p]) p--;
    while(p >= 0) printf("%d", s[p--]);
    printf("\n");
    return 0;
}