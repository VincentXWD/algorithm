//这题WA了，我觉得有问题…有问题……
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
int level;
int weekend;
int bh, bm;
int eh, em;
char cmd[55];

int main() {
//    freopen("in","r",stdin);
    int i, j, k;
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", cmd);
        level = 0x7f7f7f; weekend = 111;
        if(strcmp(cmd, "beginner") == 0) level = 10;
        if(strcmp(cmd, "middle") == 0) level = 11;
        if(strcmp(cmd, "higher") == 0) level = 12;
        scanf("%d:%d", &bh, &bm);
        scanf("%d:%d", &eh, &em);
        scanf("%s", cmd);
        if(strcmp(cmd, "workday") == 0) weekend = 0;
        else if(strcmp(cmd, "weekend") == 0) weekend = 1;
        if(level == 0x7f7f7f) {
            printf("Wrong class!\n");
            continue;
        }
        if(weekend == 111) {
            printf("Wrong days!\n");
            continue;
        }
        if(!(bh >= 0 && bh <= 23 && eh >= 0 && eh <= 23 && bm >= 0 && bm <= 59 && em >= 0 && em <= 59)) {
            printf("Wrong time!\n");
            continue;
        }
        if(bh > eh) {
            printf("Wrong time!\n");
            continue;
        }
        if(bh == eh && bm > em) {
            printf("Wrong time!\n");
            continue;
        }
        double sum = 0;
        double t = eh * 60 + em - bh * 60 - bm;
        if(eh >= 22) sum += ((eh - 22) * level) * 0.5;
        sum += (t * level) / 60;
        if(weekend) sum *= 1.5;
        printf("%.2lf\n", sum);
    }
    return 0;
}    