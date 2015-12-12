/*
本场码农题
注意题目要求，暴力写即可
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

const int maxn = 33;
const int maxm = 22;

typedef struct Node {
	char mov[maxn];
	char dir[maxn];
	char art[maxn];
}Node;

bool cmp(Node a, Node b) {
	int mm = strcmp(a.mov, b.mov);
	int dd = strcmp(a.dir, b.dir);
	int aa = strcmp(a.art, b.art);
	if(mm == 0) {
		if(dd == 0) return aa < 0;
		else return dd < 0;			
	}
	else return mm < 0;
}

int n;
Node x[maxm];
const char dir[maxm][maxm] = {"ChristopherNolan", "JohnWoo", "StevenSpielberg", "JamesCameron", "AnLee"};
const char art[maxm][maxm] = {"JenniferLawrence", "EmmaWatson", "ChristianBale", "AnneHathaway", "MattDamon", "TomCruise"};
int flag[maxn];
int num[maxn];
int cntd, cnta;

void init() {
	cntd = 0, cnta = 0;
	memset(flag, 0, sizeof(flag));
	memset(num, 0, sizeof(num));
	for(int i = 0; i <= maxn; i++) {
		memset(x[i].mov, 0, sizeof(x[i].mov));
		memset(x[i].dir, 0, sizeof(x[i].dir));
		memset(x[i].art, 0, sizeof(x[i].art));
	}
}

void input() {
	for(int i = 0; i < n; i++) {
		scanf("%s %s %s", x[i].mov, x[i].dir, x[i].art);
	}
}

void solve() {
	int cnt = 1;
	int cur = 0;
	bool numflag = 0;
	sort(x, x + n, cmp);
	for(int i = 0; i < n; i++) {	//O(n)
		int pp = x[i].mov[strlen(x[i].mov)-1] - '0';
		if(pp == cnt) {
			if(!numflag) {
				cur++;
				numflag = 1;
			}
			num[i] = cur;
			cnt++;
		}
		else {
			if(pp == 1) {
				num[i] = ++cur;
				cnt = 2;
			}
			else {			
				cnt = 1;
				numflag = 0;
			}
		}
	}
	for(int k = 0; k < n; k++) {	//O(n)
		for(int i = 0; i < 5; i++) {
			if(strcmp(x[k].dir, dir[i]) == 0) flag[k]++;
		}
		for(int j = 0; j < 6; j++) {
			if(strcmp(x[k].art, art[j]) == 0) flag[k]++;
		}
	}
	for(int k = cur; k > 0; k--) {	//O(2n)
		int maxo = 0;
		for(int i = 0; i < n; i++) {
			if(num[i] == k) {
				maxo = maxo > flag[i] ? maxo : flag[i];
			}
		}
		for(int i = 0; i < n; i++) {
			if(num[i] == k) {
				flag[i] = maxo;
			}
		}
	}
}

void output() {
	for(int k = 2; k >= 0; k--) {
		for(int i = 0; i < n; i++) {
			if(flag[i] == k) {
				printf("%s\n", x[i].mov);
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	while(~scanf("%d", &n)) {
		init();
		input();
		solve();
		output();
	}
	return 0;
}
