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

const int maxn = 66666;
int na;
char a[maxn];
char* b = "QAQ";
int nb = strlen(b);
int pre[maxn];

void getpre(char *b, int *pre) {
    int j, k;
    pre[0] = -1;
    j = 0;
    k = -1;
    while(j < nb) {
        if(k == -1 || b[j] == b[k]) {
            j++;
            k++;
            pre[j] = k;
        }
        else {
            k = pre[k];
        }
    }
}

int kmp() {
    int ans = 0;
    int i = 0;
    int j = 0;
    while(i < na) {
        if(j == -1 || a[i] == b[j]) {
            i++;
            j++;
        }
        else {
            j = pre[j];
        }
        if(j == nb) {
            ans++;
        }
    }
    return ans;
}

int main() {
    getpre(b, pre);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(a, 0, sizeof(a));
        scanf("%s", a);
        na = strlen(a);
        printf("%d\n", kmp());

    }
    return 0;
}
