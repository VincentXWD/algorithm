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


int main() {
    char str[55];
    while(~scanf("%s", str)) {
        int sum = 0;
        for(int i = 0; str[i]; i++) {
            sum += str[i] - '0';
        }
        if(sum % 3 == 0) {
            printf("YES\n");
        }
        else if((str[strlen(str)-1]-'0') % 2 == 0 || str[strlen(str)-1] == '5') {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
