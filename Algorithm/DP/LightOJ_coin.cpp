#include<bits/stdc++.h>
using namespace std;

int target,n;
long long coin[1005],uses[1005];
long long dp[1005][51];
long long coin_maker(int amount,int index)
{
    if(index==n)
    {
        if(amount==0) return 1;
        return 0;
    }
    if(amount==0)
    {
        return 1;
    }


    if(amount<0)
    {
        return 0;
    }

    if(dp[amount][index] != -1)
    {
        return dp[amount][index];
    }

    long long result = 0;
    for(int i=0; i<=uses[index]; i++)
    {
        result = (result +  coin_maker(amount - coin[index]*i, index+1)) %100000007;
    }

    dp[amount][index] = result;
    return result;
}
main()
{

    freopen("input","r",stdin);
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&target);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&coin[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&uses[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",++cas,coin_maker(target,0)%100000007);
    }
}



