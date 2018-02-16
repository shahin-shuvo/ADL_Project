
#include<bits/stdc++.h>
using namespace std;

int multi[1000][1000];
int a[1000];
int n;

int LIS(int pos,int last)
{
    if(pos>n) return 0;
    if(multi[pos][last] != -1) return multi[pos][last];
    int x=0,y=0;
    if(a[pos]>a[last]) x= a[pos]+LIS(pos+1,pos);
    y=LIS(pos+1,last);
    return multi[pos][last] =max(x,y);
}

main()
{
    int test,t=0;
    cin>>test;
    while(test--)
    {
        memset(multi,-1,sizeof(multi));
        cin>>n;
        a[0]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];

        }
        int result = LIS(1,0);
        cout<<"Case "<<++t<<": "<<result<<endl;
    }
}
