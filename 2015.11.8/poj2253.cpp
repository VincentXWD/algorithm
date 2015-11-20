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


const float inf = 2147483600;
const int maxn = 222;
int n;
bool vis[maxn];
float d[maxn];
float x[maxn],y[maxn];

float dis(int a,int b) {
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

void dijkstra() {
	for(int i = 0; i < n; i++) {
		d[i] = inf;
		vis[i] = 0;
	}
	d[0] = 0;
	for(int i = 0; i < n; i++) {
		int u = inf, ii;
		for(int j = 0; j < n; j++) {		
			if(!vis[j] && u > d[j]){
				u = d[j];
				ii = j;
			}
		}
		vis[ii] = 1;
		for(int j = 0; j < n; j++) {
			d[j] = min(d[j], max(d[ii], dis(ii, j)));
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	int _ = 0;
	while(~scanf("%d", &n) && n){
		for(int i = 0; i < n; i++) {
			scanf("%f %f", &x[i], &y[i]);
		}
		dijkstra();
		printf("Scenario #%d\n", ++_);
		printf("Frog Distance = %.3f\n\n", d[1]);
	}
	return 0;
}
