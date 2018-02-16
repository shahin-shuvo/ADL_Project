#include<bits/stdc++.h>
using namespace std;
int n,cap,member;
int we[1005],cost[1005];
int totalValue;
int dp[1001][31];
int knapsack(int i,int w)
{
    int x,y;
    if(i==n+1) return 0;
    if(dp[i][w]!=0) return dp[i][w];
    if(w+we[i]<=cap)
    {
        x= cost[i]+knapsack(i+1,w+we[i]);
    }
    else x =0;
    y = knapsack(i+1,w);
    dp[i][w] = max(x,y);
    return dp[i][w];
}
main()
{
   // freopen("input","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
    cin>>n;
    for(int i =1 ; i<=n ; i ++)
    {
       // cin>>cost[i]>>we[i];
        scanf("%d %d",&cost[i],&we[i]);
    }
    //cin>>member;
    scanf("%d",&member);
    int carry[member];
    for(int i =1 ; i<=member ; i ++)
    {
       // cin>>carry[i];
        scanf("%d",&carry[i]);
    }
    for(int i =1 ; i<=member ; i ++)
    {
        memset(dp,0,sizeof(dp));
        cap = carry[i];

        totalValue+=knapsack(1,0);
    }
    //cout<<totalValue<<endl;
    printf("%d\n",totalValue);
    totalValue =0;
    }
}

