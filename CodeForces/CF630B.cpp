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

int n, t;
int main() {
    while(~scanf("%d %d", &n, &t)) {
        printf("%1.12f\n",n*pow(1.000000011,t));
    }
    return 0;
}