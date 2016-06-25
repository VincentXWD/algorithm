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
int a[maxn];
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}

int main() {
    //freopen("in","r",stdin);
    int i, j, k;
    for(i = 0; i < 7; i++) {
        scanf("%d", &a[i]);
    }
    int nn = 1 << 7;
    int t = 0;
    vector<int> v;
    bool flag = 0;
    for(i = 0; i < nn; i++) {
        v.clear();
        t = 0;
        for(int j = 0; j < 7; j++) {
            if(i & (1 << j)) {
                v.push_back(a[j]);
                t += a[j];
            }
        }
        if(t  == 100) {
            flag = 1;
            for(int i = 0; i < v.size(); i++) {
                printf("%3d", v[i]);
                if(i == v.size() - 1) printf("\n");
            }
        }
    }
    if(flag == 0) printf("No!\n");
    return 0;
}