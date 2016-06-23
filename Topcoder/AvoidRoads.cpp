// BEGIN CUT HERE

// END CUT HERE
#line 5 "AvoidRoads.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long ll;
const int mod = 1000007;
bool cut[mod];
unsigned long long dp[130][130];

int cv(int x1, int y1, int x2, int y2) {
	return ((((x1 * 1007 % mod) + y1 * 737 % mod) + x2 * 103) % mod + y2 * 71) % mod;
}

class AvoidRoads
{
        public:
        long long numWays(int width, int height, vector<string> bad) {
        	int x1,y1,x2,y2;
        	int& n = width;
        	int& m = height;
			memset(cut, 0, sizeof(cut));
			memset(dp, 0, sizeof(dp));
			for(int i = 0; i < bad.size(); i++) {
				stringstream ss;
				ss << bad[i];
				ss >> x1 >> y1 >> x2 >> y2;
				cut[cv(x1,y1,x2,y2)] = 1;
				cut[cv(x2,y2,x1,y1)] = 1;

			}
			dp[0][0] = 1;
			for(int i = 0; i < n; i++) {
				if(!cut[cv(i,0,i+1,0)]) dp[i+1][0] = dp[i][0];
				else break;
			}
			for(int i = 0; i < m; i++) {
				if(!cut[cv(0,i,0,i+1)]) dp[0][i+1] = dp[0][i];
				else break;
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if(!cut[cv(i-1,j,i,j)]) dp[i][j] += dp[i-1][j];
					if(!cut[cv(i,j-1,i,j)]) dp[i][j] += dp[i][j-1];
				}
			}
			return dp[n][m];
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 6; string Arr2[] = {"0 0 0 1","6 6 5 6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 252LL; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 35; int Arg1 = 31; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6406484391866534976LL; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        AvoidRoads ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
