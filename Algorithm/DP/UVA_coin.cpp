#include<bits/stdc++.h>
using namespace std;

int target;
int coin[]={50,25,10,5,1};
int dp[5][7850];
int coin_maker(int i,int amount)
{
    if(i>=5)
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

    return dp[i][amount] = x+y;
}
main()
{
    while( scanf("%d",&target)!=EOF)
    {
    memset(dp,-1,sizeof(dp));
    printf("%d\n",coin_maker(0,0));
    }
}


