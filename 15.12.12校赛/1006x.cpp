/*
首先考虑一个成绩不删除的情况
再每次拿出一个成绩，判断是否合理
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

const int maxn = 111;
int n, flag, cur;
int s[maxn];
bool vis[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
		}
		flag = 0;
		for(int i = 1; i < n; i++) {
			if(s[i-1] <= s[i]) continue;
			flag = 1;
		}
		if(!flag) {
			printf("Yes\n");
			continue;
		}
		int tmp[maxn];
		int k = 0;
		for(int i = 0; i < n; i++) {
			memset(vis, 0, sizeof(vis));
			memset(tmp, 0, sizeof(tmp));
			flag = 0;
			vis[i] = 1;
			cur = s[i];
			k = 0;
			for(int j = 0; j < n; j++) {
				if(!vis[j]) tmp[k++] = s[j];
			}
			for(int j = 1; j < k; j++) {
				if(tmp[j-1] <= tmp[j]) continue;
				flag = 1;
				break;
			}
			if(!flag) {
				break;
			}
		}
		if(flag) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
