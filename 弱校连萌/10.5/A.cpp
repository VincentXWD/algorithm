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

const int INF = 0x3f3f3f3f;
const int maxn = 110;
int n;
int ans[maxn];
int Left[maxn];
bool S[maxn],T[maxn];
double px[maxn<<1];
double py[maxn<<1];
double Lx[maxn],Ly[maxn];
double dis[maxn][maxn];


bool match(int i)
{
    S[i]=true;
    for(int j=1;j<=n;j++)if(abs(Lx[i]+Ly[j]-dis[i][j])<1e-5&&!T[j])
    {
        T[j]=true;
        if(Left[j]==0||match(Left[j]))
        {
            Left[j]=i;
            return true;
        }
    }
    return false;
}
void update(){
    double a=INF;
    for(int i=1;i<=n;i++)if(S[i])
        for(int j=1;j<=n;j++)if(!T[j])
            a=min(a,Lx[i]+Ly[j]-dis[i][j]);
    for(int i=1;i<=n;i++){
        if(S[i])Lx[i]-=a;
        if(T[i])Ly[i]+=a;
    }
}
void KM()
{
    for(int i=1;i<=n;i++){
        Left[i]=Lx[i]=Ly[i]=0;
        for(int j=1;j<=n;j++)
        {
            Lx[i]=max(Lx[i],dis[i][j]);
        }
    }
    for(int i=1;i<=n;i++) 
    {
        while(1) 
        {
        	memset(S,0,sizeof(S));
        	memset(T,0,sizeof(T));
            if(match(i)) break;
            else update();
        }
    }
}

inline double dist(double x1, double y1, double x2, double y2) {
	return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

int main() {
	// freopen("in", "r", stdin);
	double x, y;
	while(~scanf("%d", &n)) {
		memset(ans, 0, sizeof(ans));
		memset(px, 0, sizeof(px));
		memset(py, 0, sizeof(py));
		for(int i = 1; i <= 2*n; i++) {
			scanf("%lf %lf", &px[i], &py[i]);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = -dist(px[i], py[i], px[j+n], py[j+n]);
			}
		}
		KM();
		for(int i = 1; i <= n; i++) {
			ans[Left[i]] = i;
		}
		for(int i = 1; i <= n; i++) {
			printf("%d\n", ans[i]);
		}
	}
}
