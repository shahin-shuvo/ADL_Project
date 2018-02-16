#include<bits/stdc++.h>
using namespace std;

long long dp[1000][10000];

long long  nCr_DP(long long n,long long r)
{
    if(r==1) return n;
    if(n==r) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    else{
        dp[n][r] = nCr_DP(n-1,r) + nCr_DP(n-1,r-1);
        return dp[n][r];
    }
}
main()
{
    long long n,r;
    memset(dp,-1,sizeof(dp));
    cin>>n>>r;
    cout<<nCr_DP(n,r)<<endl;
}

