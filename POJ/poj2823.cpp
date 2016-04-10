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

inline bool scan_d(int &num) {
	char in;bool IsN=false;
	in=getchar();
	if(in==EOF) return false;
	while(in!='-'&&(in<'0'||in>'9')) in=getchar();
	if(in=='-'){ IsN=true;num=0;}
	else num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
			num*=10,num+=in-'0';
	}
	if(IsN) num=-num;
	return true;
}

typedef struct Node {
	int idx;
	int val;
	Node() {}
	Node(int ii, int vv) : idx(ii), val(vv) {}
}Node;
const int maxn = 1000010;
int n, k;
int a[maxn];
Node q[maxn];
int front, tail;

int main() {
//	freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &k)) {
		for(int i = 0; i < n; i++) {
			scan_d(a[i]);
		}
		front = 0,  tail = 0;
		q[tail++] = Node(0, a[0]);
		int ans[maxn], cnt = 0;
		for(int i = 1; i < k; i++) {
			while(front < tail && q[tail-1].val >= a[i]) {
				tail--;
			}
			q[tail++] = Node(i, a[i]);
		}
		ans[cnt++] = q[front].val;
		for(int i = k; i < n; i++) {
			while(front < tail && q[tail-1].val >= a[i]) {
				tail--;
			}
			while(front < tail && i - k + 1 > q[front].idx) {
				front++;
			}
			q[tail++] = Node(i, a[i]);
			ans[cnt++] = q[front].val;
		}
		for(int i = 0; i < cnt; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
		front = 0, tail = 0;
		q[tail++] = Node(0, a[0]);
		cnt = 0;
		for(int i = 1; i < k; i++) {
			while(front < tail && q[tail-1].val <= a[i]) {
				tail--;
			}
			q[tail++] = Node(i, a[i]);
		}
		ans[cnt++] = q[front].val;
		for(int i = k; i < n; i++) {
			while(front < tail && q[tail-1].val <= a[i]) {
				tail--;
			}
			while(front < tail && i - k + 1 > q[front].idx) {
				front++;
			}
			q[tail++] = Node(i, a[i]);
			ans[cnt++] = q[front].val;
		}
		for(int i = 0; i < cnt; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}
