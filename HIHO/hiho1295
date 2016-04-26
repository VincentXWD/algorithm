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

const int maxn = 1000010;
bool isprime[maxn];
int prime[maxn];
int pcnt;
int n;

void init() {
    memset(isprime, true, sizeof(isprime));
    memset(prime, 0, sizeof(prime));
    pcnt = 0;
}

void getPrime() {
    prime[0] = prime[1] = 0;
    for(int i = 2; i < maxn; i++) {
        if(isprime[i]) prime[++pcnt] = i;
        for(int j = 1; j <= pcnt; j++) {
            if(i * prime[j] > maxn) break;
            isprime[i*prime[j]] = 0;
            if(i % prime[j] == 0) break;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    init();
    n = maxn;
    getPrime();
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= maxn; i++) {
        if(n >= prime[i]) cnt++;
        else break;
    }
    printf("%d\n", cnt);
    return 0;
}