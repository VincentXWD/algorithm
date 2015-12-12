/*
素数 打表
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

const int maxn = 1000;
bool isprime[maxn];
int cnt;

void printlist() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    int pedge = int(sqrt(maxn));
    for(int i = 2; i <= pedge; i++) {
        if(isprime[i]) {
            int o = maxn / i;
            for(int j = 2; j <= o; j++) {
                isprime[i*j] = false;
            }
        }
    }
} 

int main() {
	printlist();
	cnt = 0;
	for(int i = 2; i <= 1000; i++) {
		if(isprime[i] && isprime[i-2]) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}