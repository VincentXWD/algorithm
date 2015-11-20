#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;
char s[100];
int main()
{
    int n,i,j;
    while(cin>>n)
    {
        cout<<n<<" "<<n<<" "<<2<<endl;;
        for(i=0;i<n;i++)
        {
            if(i<=25)
            {
                s[i]='a'+i;
            }
            else
            {
                s[i]='A'+i-26;
            }
        }
        for(j=0;j<n;j++)
        {
            for(i=0;i<n;i++)
            {
                if(j<26)
                {
                    cout<<char('a'+j);
                }
                else
                {
                    cout<<char('A'+j-26);
                }
            }
            cout<<endl;
            for(i=0;i<n;i++)
            {
                cout<<s[i];
            }
            cout<<endl;
            cout<<endl;
        }
    }
    return 0;
}