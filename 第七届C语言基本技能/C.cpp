#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 11;
char s[maxn];
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}
char tmp[180];
void work(char x) {
    int i;
    int cur = 0;
    memset(tmp, 0, sizeof(tmp));
    int q;
    while(x) {
        q = x % 2;
        tmp[cur++] = q + '0';
        x /= 2;
    }
    while(cur < 10) tmp[cur++] = '0';
    int cnt = 0;
    for(i = 0; i < cur; i++) {
        if(tmp[i] == '1') cnt++;
    }
    if(cnt & 1) tmp[7] = '0';
    else tmp[7] = '1';
    for(i = 7; i >= 0; i--) printf("%c", tmp[i]);
    printf("\n");
}

int main() {
    //freopen("in","r",stdin);
    int i, j, k;
    while(gets(s)) {
        int n = strlen(s);
        for(int i = 0; i < n; i++) {
            work(s[i]);
        }
    }
    return 0;
}