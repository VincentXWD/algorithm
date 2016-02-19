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

const double eps = 1e-8;

int main() {
	double a, b, c;
	while(~scanf("%lf %lf %lf", &a, &b, &c)) {
		if(a > eps) {
			printf("%.10f\n%.10f\n", (-b+sqrt(b*b-4*a*c))/(2*a), (-b-sqrt(b*b-4*a*c))/(2*a));
		}
		else if(a < -eps) {
			printf("%.10f\n%.10f\n", (-b-sqrt(b*b-4*a*c))/(2*a), (-b+sqrt(b*b-4*a*c))/(2*a));
		}
		else {
			printf("%.10f\n%.10f\n", -c/b, -c/b);
		}
	}
	return 0;
}