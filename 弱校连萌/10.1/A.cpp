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

int n;
int tmp;

int main() {
    while(~scanf("%d", &n)) {
        int flag = true;
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            double sq = sqrt(tmp);
            if(int(sq) != sq) {
                flag = false;
            }
        }
        if(flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}