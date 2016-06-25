#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const int maxn = 555;
char s[maxn];
char tmp[555];
int n, len;
vector<float> v;

int main() {
    //freopen("in", "r", stdin);
    int i, j, k;
    while(gets(s)) {
        v.clear();
        n = strlen(s);
        i = 0;
        while(i < n) {
            if(s[i] >= '0' && s[i] <= '9') {
                memset(tmp, 0, sizeof(tmp));
                len = 0;
                while((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
                    tmp[len++] = s[i];
                    i++;
                }
                float q;
                sscanf(tmp, "%f", &q);
                v.push_back(q);
            }
            i++;
        }
        float x = 0;
        for(i = 0; i < v.size(); i++) {
            x += v[i];
            printf("%8.2f",v[i]);
        }
        printf("%8.2f\n", x);
    }
    return 0;
}