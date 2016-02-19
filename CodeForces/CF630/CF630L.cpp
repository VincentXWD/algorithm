#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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

typedef long long LL;
char n[10];

int main() {
	while(~scanf("%s", n)) {	
	    swap(n[1], n[2]);
	    swap(n[2], n[4]);
	    LL t = 0;
	    for(int i = 0; i < 5; i++)
	        t = t * 10 + n[i] - '0';
	    LL tt = 1;
	    for(int i = 0; i < 5; i++)
	        tt = tt * t % 100000;
	    printf("%05I64d\n", tt);
	}
    return 0;
}