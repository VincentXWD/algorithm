/*
进制转换模拟即可
贪心求出关键语句
递归输出结果
*/
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

const int maxn = 11000000;
const char* L = "0123456789ABCDEF";
int r1, r2;
char str[maxn];

void pr(int a,int b) {
	if(a == 0) return;
	pr(a/b, b);
	printf("%c", L[a%b]);
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%s%*c%d %d%*c", str, &r1, &r2)) {
		int lcl = 0, cl = 0, ed = -1;
		for(int i = 0; str[i]; i++) {
			if(str[i] >= 'a' && str[i] <= 'z') {
				++cl;
			}
			else {
				cl = 0;
			}
			if(lcl < cl) {
				lcl = cl;
				ed = i;
			}
			if(str[i] & 1) {
				pr(str[i], r1);
			}
			else {
				pr(str[i], r2);
			}
		}
		printf("\n%d\n", lcl);
		for(int i = ed-lcl+1; i <= ed; i++) {
			printf("%c", str[i]+'A'-'a');
		}
		printf("\n");
	}
	return 0;
}
