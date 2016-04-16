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

int n;
multiset<int> gg;
multiset<int>::iterator it, p;

int main() {
    // freopen("in", "r", stdin);
    char cmd[11];
    int a;
    while(~scanf("%d", &n)) {
        gg.clear();
        while(n--) {
            scanf("%s", cmd);
            scanf("%d", &a);
            if(cmd[1] == 'u') {
                gg.insert(a);
            }
            if(cmd[1] == 'o') {
                if(a < *(gg.begin())) {
                    printf("No Element!\n");
                    continue;                    
                }
                it = gg.find(a);
                if(it == gg.end()) {
                    gg.insert(a);
                    it = p = gg.find(a);
                    it--;
                    printf("%d\n", *it);
                    gg.erase(it);
                    gg.erase(p);
                }
                else {
                    printf("%d\n", a);
                    gg.erase(it);
                }
            }
        }
        printf("\n");
    }
    return 0;
}