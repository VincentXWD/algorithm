/*
数据范围很大，朴素的O(n^2)无法解决
用O(nlgn)以下的排序算法可以解决
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

const int maxn = 111111;
int r[maxn], p[maxn];
int n, m;
int bucket[10010];

inline void input(int* a, int b) {
	for(int i = 0; i < b; i++) {
		scanf("%d", &a[i]);
	}
}

void buck(int* a, int b) {
	memset(bucket, 0, sizeof(bucket));
	for(int i = 0; i < b; i++) {
		bucket[a[i]]++;
	}
	int cnt = 0;
	for(int i = 0; i < 10010; i++) {	//O(10010+∑bucket[i])=O(n)+k
		if(bucket[i] != 0)
		for(int j = 0; j < bucket[i]; j++) {
			a[cnt++] = i;
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		input(r, n);
		input(p, m);
		buck(r, n);
		buck(p, m);
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(r[i] >= p[cnt]) {
				cnt++;
			}
		}
		printf("%d\n", cnt >= m ? m : cnt);
	}
	return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <iomanip>
// #include <cstring>
// #include <climits>
// #include <complex>
// #include <fstream>
// #include <cassert>
// #include <cstdio>
// #include <bitset>
// #include <vector>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <ctime>
// #include <set>
// #include <map>
// #include <cmath>

// using namespace std;

// const int maxn = 100000;
// int n, m;
// int r[maxn], p[maxn];

// int main() {
//     // freopen("in", "r", stdin);
//     // freopen("out", "w", stdout);
//     while(~scanf("%d %d", &n, &m)) {
//         for(int i = 0; i < n; i++) {
//             scanf("%d", &r[i]);
//         }
//         for(int i = 0; i < m; i++) {
//             scanf("%d", &p[i]);
//         }
//         sort(r, r+n);
//         sort(p, p+m);
//         int cnt = 0;
//         for(int i = 0; i < n; i++) {
//             if(r[i] >= p[cnt]) {
//                 cnt++;
//             }
//         }
//         printf("%d\n", cnt > m ? m : cnt);
//     }
// }
