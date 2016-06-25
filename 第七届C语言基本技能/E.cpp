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
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}
int a, b;
typedef struct P {
    int idx;
    int score;
    int shoot;
    int clea;

}P;
P p[maxn];
int n;
bool cmp(P a, P b) {
    if(a.score != b.score) return a.score > b.score;
    if(a.clea != b.clea) return a.clea > b.clea;
    if(a.shoot != b.shoot) return a.shoot > b.shoot;
    return a.idx < b.idx;
}

int main() {
    //freopen("in","r",stdin);
    int i, j, k;
    n = 4;
    memset(p, 0, sizeof(p));
    for(i = 1; i <= n; i++) {
        p[i].idx = i;
        p[i].score = p[i].shoot = p[i].clea = 0;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == j) continue;
            scanf("%d:%d", &a, &b);
            p[i].shoot += a;
            p[i].clea = p[i].clea + a - b;
            p[j].shoot += b;
            p[j].clea = p[j].clea + b - a;
            if(a > b) {
                p[i].score += 3;
            }
            else if(a == b) {
                p[i].score++; p[j].score++;
            }
            else if(a < b) {
                p[j].score += 3;
            }
        }
    }
    sort(p+1, p+n+1, cmp);
    printf("第%d队\n", p[1].idx);
    return 0;
}