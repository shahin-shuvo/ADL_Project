#include<bits/stdc++.h>
using namespace std;

int n,target;
int coin[100];
int dp[1001][31];
int coin_maker(int i,int amount)
{

    if(i>=n+1)
    {
        if(amount==target) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];
    int x=0,y=0;
    if(coin[i]+amount<=target)
    {
        x=coin_maker(i,amount+coin[i]);
    }
    y = coin_maker(i+1,amount);

    return dp[i][amount] = x||y;
}
main()
{
    cin>>n>>target;
    memset(dp,-1,sizeof(dp));
    for(int i =1 ; i<=n ; i ++)
    {
        cin>>coin[i];
    }
    cout<<coin_maker(1,0)<<endl;
}

