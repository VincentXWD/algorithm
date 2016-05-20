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
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int inf = 0x7f7f7f;
const int maxn = 100010;

typedef struct Heap {
	int heap[maxn];
	int pos, size;
	void init() {
		pos = 0; size = 0;
		memset(heap, inf, sizeof(heap));
		heap[0] = inf;
	}
	void push(int x) {
		int i = ++pos;
		for(; heap[i>>1] < x; i>>=1) heap[i] = heap[i>>1];
		heap[i] = x; size++;
	}
	void pop() {
		if(pos == 0) return;
		int child = 1;
		int i = 1;
		int last = heap[pos--];
		for(; i<<1 <= pos; i=child) {
			child = i<<1;
			if(child != pos && heap[child] < heap[child+1]) ++child;
			if(last < heap[child]) heap[i] = heap[child];
			else break;
		}
		heap[i] = last; size--;
	}
	int top() { return heap[1]; }
}Heap;

int n;
int q[maxn], front, tail;
int s[maxn], top;
Heap h;
int a1[maxn], a2[maxn], a3[maxn];
int a4[maxn];
int p1, p2, p3, p4;
int f1, f2, f3, f4;

int main() {
	// FRead();
	int a, b;
	while(~Rint(n)) {
		p1 = p2 = p3 = p4 = 0;
		f1 = f2 = f3 = 1;
		f4 = front = tail = top = 0;
		h.init();
		W(n) {
			Rint(a); Rint(b);
			if(a == 1) {
				q[tail++] = b;
				s[top++] = b;
				h.push(b);
			}
			if(a == 2) {
				a4[p4++] = b;
				if(tail > front) b = q[front++], a1[p1++] = b;
				if(top != 0) b = s[--top], a2[p2++] = b;
				if(h.size != 0) b = h.top(), h.pop(), a3[p3++] = b;
			}
		}
		Rep(i, p4) {
			if(a4[i] != a1[i]) f1 = 0;
			if(a4[i] != a2[i]) f2 = 0;
			if(a4[i] != a3[i]) f3 = 0;
		}
		f4 = f1 + f2 + f3;
		if(f4 > 1) printf("not sure\n");
		else if(f4 == 0) printf("impossible\n");
		if(f4 == 1) {
			if(f1) printf("queue\n");
			if(f2) printf("stack\n");
			if(f3) printf("priority queue\n");
		}
	}
	RT 0;
}