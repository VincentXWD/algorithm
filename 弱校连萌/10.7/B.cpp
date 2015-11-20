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

typedef struct Point {
	int x;
	int y;
	friend bool operator ==(Point a, Point b) {
		return a.x == b.x && a.y == b.y;
	}
};

Point p[4];

bool reapeat() {
	int i = 0, j;
    for(; i < 4; i++) {
    	for(j = i+1; j < 4; j++) {
    		if(p[i] == p[j]) {
    			break;
    		}
    	}
    	if(j != 4) {
    		break;
    	}
    }
    return i != 4;
}

bool par() {
	int a = (p[1].y - p[0].y) * (p[3].x - p[2].x);
    int b = (p[1].x - p[0].x) * (p[3].y - p[2].y);
    int c = (p[2].x - p[1].x) * (p[3].y - p[0].y);
    int d = (p[3].x - p[0].x) * (p[2].y - p[1].y);
    if(a != b) {
    	return false;
    }
    return c == d;
}

bool rec() {
	int a = (p[0].x - p[2].x) * (p[0].x - p[2].x) + (p[0].y - p[2].y) * (p[0].y - p[2].y);
    int b = (p[1].x - p[3].x) * (p[1].x - p[3].x) + (p[1].y - p[3].y) * (p[1].y - p[3].y);
    return a == b;
}

bool dia() {
	int a = (p[0].y - p[2].y) * (p[1].y - p[3].y);
    int b = (p[1].x - p[3].x) * (p[0].x - p[2].x);
    return a == -b;
}

int main() {
    // freopen("in", "r", stdin);
    int kase = 0;
    int T_T;
    scanf("%d", &T_T);
    while(T_T--) {
        printf("Case #%d: ", ++kase);
        for(int i = 0; i < 4; i++) {
        	scanf("%d %d", &p[i].x, &p[i].y);
        }
        if(reapeat()) {
        	printf("Others\n");
        }
        else {
        	if(par()) {
        		bool flag1 = rec();
        		bool flag2 = dia();
        		if(flag1 && flag2) {
        			printf("Square\n");
        		}
        		else if(!flag1 && !flag2) {
        			printf("Parallelogram\n");
        		}
        		else if(flag1) {
        			printf("Rectangle\n");
        		}
        		else if(flag2) {
        			printf("Diamond\n");
        		}
        	}
        	else {
	        	printf("Others\n");
        	}
        }
    }
}
