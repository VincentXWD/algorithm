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

const int maxn = 100100;
string s, t;
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}

int main() {
    //freopen("in","r",stdin);
    int i, j, k;
    while(cin >> s >> t) {
        if(strcmp(s.c_str(), "end") == 0 && strcmp(t.c_str(), "end") == 0) break;
        int n = s.length();
        int m = t.length();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                int a = i, b = j;
                while(s[a] == t[b] && a < n && b < m) {
                    a++; b++;
                    cnt++;
                }
                mx = max(mx, cnt);
            }
        }
        double qq = double((double)mx / double(min(n, m)));
        if(qq > 0.5) printf("Not pass\n");
        else printf("Pass\n");
    }
    return 0;
}