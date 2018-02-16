#include<bits/stdc++.h>
#define inf 1<<28
using namespace std;
int n;
int banana[200][200], dp[200][200];

int monkeyBanana(int i, int j)
{
    if(i>=0 && i<2*n-1 && j>=0 && j<n)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(banana[i][j]==0) return 0;
        int res=-10009;
        res=max(res, monkeyBanana(i+1, j)+banana[i][j]);
        if(i<n-1) res=max(res, monkeyBanana(i+1, j+1)+banana[i][j]);
        else res=max(res, monkeyBanana(i+1, j-1)+banana[i][j]);

        dp[i][j]=res;
        return dp[i][j];
    }
    else return 0;

}

int main()
{
   // freopen("input","r",stdin);

    int test, tc=1;
    cin>>test;
    while(test--)
    {
        memset(dp, -1, sizeof(dp));
        memset(banana, 0, sizeof(banana));
        cin>>n;
        int a;
        for(int i=0; i<2*n-1; i++)
        {
            if(i<n)
                for(int j=0; j<=i; j++)
                    cin>>banana[i][j];
            else
                for(int j=0; j<2*n-i-1; j++)
                    cin>>banana[i][j];
        }
        int res=monkeyBanana(0, 0);
        cout<<"Case "<<tc++<<": "<<res<<endl;
    }
    return 0;
}
