#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

const int maxn = 550;
char tmp[maxn];
map<string, int> p;

int main() {
	// freopen("in", "r", stdin);
	p.clear();
	while(gets(tmp) && tmp[0] != '#') {
		for(int i = 0; tmp[i]; i++) {
			if(tmp[i] >= 'A' && tmp[i] <= 'Z') {
				tmp[i] = tmp[i] - 'A' + 'a';
			}
		}
		char w[55];
		char* k = strtok(tmp, " ");
		while(k) {
			sscanf(k, "%s", w);
			p[w]++;
			k = strtok(NULL, " ");
		}
		p[tmp]++;
	}
	map<string, int>::iterator it;
	string t = " ";
	int cur = 0;
	for(it = p.begin(); it != p.end(); it++) {
		if(it->second > cur) {
			cur = it->second;
			t = it->first;
		}
		else if(it->second == cur) {
			if(t > it->first) t = it->first;
		}
	}
	cout << t << endl;
	return 0;
}
