/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
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
#define fr first
#define sc second
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Fuint(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long Uint;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 110;
char s[maxn];
int fa, fb;
int main() {
	// FRead();
	int T;
	Rint(T);
	getchar();
	W(T) {
		fa = fb = 0;
		gets(s);
		int n = strlen(s);
		if(n < 5) {
			printf("OMG>.< I don't know!\n");
			continue;
		}
		if(s[0]=='m'&&s[1]=='i'&&s[2]=='a'&&s[3]=='o'&&s[4]=='.') fa = 1;
		if(s[n-5]=='l'&&s[n-4]=='a'&&s[n-3]=='l'&&s[n-2]=='a'&&s[n-1]=='.') fb = 1;
		if((fa == 0 && fb == 0) || (fa == 1 && fb == 1)) printf("OMG>.< I don't know!\n");
		else {
			if(fa) printf("Rainbow's\n");
			else if(fb) printf("Freda's\n");
		}
	}
	RT 0;
}