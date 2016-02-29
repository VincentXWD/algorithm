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

typedef struct Node {
	int id;
	int x;
	Node() {}
	Node(int ii, int xx) : id(ii), x(xx) {}
}Node;

const int maxn = 111111;
int n, m;
Node a[maxn];

bool cmp(Node x, Node y) {
	return x.x < y.x;
}

int main() {
	// freopen("in", "r", stdin);
	int tmp;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			a[i] = Node(i+1, tmp);
		}
		sort(a, a+n, cmp);
		while(m--) {
			int i, j, k, ans = 0;
			scanf("%d %d %d", &i, &j, &k);
			for(int s = 0; s < n; s++) {
				if(a[s].id >= i && a[s].id <= j) k--;
				if(k == 0) {
					printf("%d\n", a[s].x);
					break;
				}
			}
		}
	}
	return 0; 
}