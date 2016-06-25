#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100100;
char s[maxn];
int n, len;

int main() {
    int i, j, k;
    while(~scanf("%d", &n)) {
        getchar();
        gets(s);
        len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                printf("%c", ((s[i]-'A')-n+5*26)%26+'A');
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                printf("%c", ((s[i]-'a')-n+5*26)%26+'a');
            }
            else printf("%c", s[i]);

        }
        printf("\n");
    }
}