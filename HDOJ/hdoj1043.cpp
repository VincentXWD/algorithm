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

typedef struct Node1 {
	char s;
	int pre;
	Node1() { pre = -1; }
}Node1;
typedef struct Node2 {
	int status[11];
	int n, son;
}Node2;

Node1 path[666666];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int fac[11];

void init() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i <= 10; i++) {
		fac[i] = fac[i-1] * i;
	}
}

int ecantor(int* s, int n = 9) {
	int num = 0;
	for(int i = 0; i < n; i++) {
		int tmp = 0;
		for(int j = i + 1; j < n; j++) {
			if(s[j] < s[i]) {
				tmp++;
			}
		}
		num += fac[n-1-i] * tmp;
	}
	return num;
}

void bfs() {
	queue<Node2> q;
	Node2 a, b;
	int t = 0;
	for(int i = 0; i < 9; i++) {
		a.status[i] = i + 1;
	}
	a.n = 8; a.son = 0;
	path[a.son].pre = 0;
	q.push(a);
	while(!q.empty()) {
		a = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			b = a;
			int xx = a.n % 3 + dx[i];
			int yy = a.n / 3 + dy[i];
			if(!(xx >= 0 && xx < 3 && yy >= 0 && yy < 3)) continue;
			b.n = yy * 3 + xx;
			swap(b.status[b.n], b.status[a.n]);
			b.son = ecantor(b.status);
			if(path[b.son].pre == -1) {
				path[b.son].pre = a.son;
				if(i == 0) path[b.son].s = 'l';
				if(i == 1) path[b.son].s = 'r';
				if(i == 2) path[b.son].s = 'u';
				if(i == 3) path[b.son].s = 'd';
				q.push(b);
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	init();
	int s, ss[11];
	char ch[55];
	bfs();
	while(gets(ch)) {
		int cnt = 0;
		for(int i = 0; ch[i]; i++) {
			if(ch[i] == 'x') {
				ss[cnt++] = 9;
			}
			else if(ch[i] >= '0' && ch[i] <= '9') {
				ss[cnt++] = ch[i] - '0';
			}
		}
		s = ecantor(ss);
		if(path[s].pre == -1) {
			printf("unsolvable\n");
			continue;
		}
		while(s != 0) {
			printf("%c", path[s].s);
			s = path[s].pre;
		}
		printf("\n");
	}
	return 0;
}
