#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 10000010;
int na, nb;
char a[maxn];
char b[maxn];
int pre[maxn];

//b是模式串，a是目标串
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
    		return i - nb;
        }
    }
    return -1;
}

void rmv(int pos) {
	for(int i = 0; i < nb; i++) {
		a[pos+i] = a[pos+nb+i];
	}
	na -= nb;
	a[na] = 0;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%s", b)) {
		scanf("%s", a);
		na = strlen(a);
		nb = strlen(b);
	    getpre(b, pre);
	    for(int i = 0; i < nb; i++) {
	    	printf("%c ", b[i]);
	    }
	    printf("\n");
	    for(int i = 1; i <= nb; i++) {
	    	printf("%d ", pre[i]);
	    }
	    printf("\n");
		if(nb > na) {
			puts(a);
			continue;
		}
		if(!kmp()) {
			puts("");
			continue;
		}
		int pos = kmp();
		while(pos != -1) {
			rmv(pos);
			pos = kmp();
		}
		puts(a);
	}
}