#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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

typedef long long LL;
int n;

int main() {
    while(~scanf("%d", &n)) {
        printf("%I64d\n", 3LL*n*(n+1LL)+1);
    }
    return 0;
}