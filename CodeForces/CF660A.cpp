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

const int maxn = 1111;
int n;
int a[maxn];
bool need[maxn];
int cnt;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int maxm = 1000010;
bool isprime[maxm];
int prime[maxm];
int pcnt;

void init() {
    memset(isprime, true, sizeof(isprime));
    memset(prime, 0, sizeof(prime));
    pcnt = 0;
}

void getPrime() {
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= maxn; i++) {
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
    getPrime();
    while(~scanf("%d", &n)) {
        memset(need, 0, sizeof(need));
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            if(gcd(a[i], a[i+1]) != 1) {
                need[i] = 1;
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < n; i++) {
            printf("%d ", a[i]);
            if(need[i]) {
                for(int j = 1; ; j++) {
                    if(gcd(prime[j], a[i]) == 1 && gcd(prime[j],a[i+1]) == 1) {
                        printf("%d ", prime[j]);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}