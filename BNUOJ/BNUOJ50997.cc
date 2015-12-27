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

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    int a, b;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        int xx = max(a, b);
        if(xx * 5 < 1000) {
            printf("1000\n");
        }
        else if(xx * 5 >= 60000) {
            printf("60000\n");
        }
        else {
            printf("%d\n", xx * 5);
        }
    }
}
