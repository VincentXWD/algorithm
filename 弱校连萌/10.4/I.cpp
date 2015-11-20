#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int bigl, smll;
int bigh, smlh;

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d %d %d", &bigl, &bigh, &smll, &smlh)) {
        float numl = floor(bigl / smll);
        float numh = floor(bigh / smlh);
        float cutl = bigl - (smll * numl);
        float cutln = floor(smll / cutl);
        float extl = ceil(numh / cutln);

        int need = 0;
        if (int(numh) % int(cutln) == 0) {
            need = 1;
        }

        float cuth = bigh - (smlh * numh);
        float cuthn = floor(smlh / cuth);

        float call = bigl;
        if (need == 0) {
            call = numl * smll;
        }
        float exth = ceil(ceil(call / smll) / cuthn);
        // printf("%lf %lf\n", need, cutln);
        printf("%d\n", int(numl * numh + extl + exth));
    }
}
