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

typedef long long LL;
const int maxn = 1000010;
char str[maxn];
char has[256];
bool ll[256], rr[256];

void work(char a, char b) {
    has[a] = b;
    has[b] = a;
    ll[a] = 1;
    rr[b] = 1;
}

void init() {
    memset(has, 0, sizeof(has));
    memset(ll, 0, sizeof(ll));
    memset(rr, 0, sizeof(rr));
    work('{', '}');
    work('<', '>');
    work('(', ')');
    work('[', ']');
}

int main() {
    // freopen("in", "r", stdin);
    init();
    while(~scanf("%s", &str)) {
        char st[maxn];
        int top = 0;
        int ans = 0;
        bool flag = 0;
        for(int i = 0; str[i]; i++) {
            if(flag) break;
            if(ll[str[i]]) {
                st[top++] = str[i];
            }
            else {
                if(top == 0) {
                    printf("Impossible\n");
                    flag = 1;
                    break;
                }
                else {
                    char tmp = st[--top];
                    if(has[str[i]] != tmp) {
                        ans++;
                    }
                }
            }
        }
        if(flag) {
            continue;
        }
        if(top != 0) {
        	printf("Impossible\n");
        }
        else {
	        printf("%d\n", ans);
        }
    }
    return 0;
}