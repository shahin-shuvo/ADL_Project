#include<bits/stdc++.h>
using namespace std;

int dp[1000];
int fibDP(int n)
{
    if (n==0) return 0;
    if(n==1) return 1;
    if(dp[n] != -1) return dp[n];
    else{
    dp[n] = fibDP(n-1) + fibDP(n-2);
    return dp[n];}
}
main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<fibDP(n)<<endl;
}
