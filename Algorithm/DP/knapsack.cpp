#include<bits/stdc++.h>
using namespace std;
int n,cap;
int we[100],cost[100];

int knapsack(int i,int w)
{
    int x,y;
    if(i==n+1) return 0;
    if(w+we[i]<=cap)
    {
        x= cost[i]+knapsack(i+1,w+we[i]);
    }
    else x =0;
    y = knapsack(i+1,w);

    return max(x,y);
}
main()
{
    cin>>n>>cap;
    for(int i =1 ; i<=n ; i ++)
    {
        cin>>we[i]>>cost[i];
    }
    cout<<knapsack(1,0)<<endl;
}
