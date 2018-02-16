#include<bits/stdc++.h>
using namespace std;

int mat[][10]=
{
    {-1,2,5},
    {4,-2,3},
    {1,2,10}
};
int dp[10][10];
int row =3,col=3;
int rockClimbing(int i,int j)
{
    if( (i>=0&&i<row) && (j>=0 && j<col) )
    {
    if(dp[i][j] != -1) return dp[i][j];
        int res = -1000099;
        res = max(res,rockClimbing(i+1,j) + mat[i][j]);
        res = max(res,rockClimbing(i+1,j-1) + mat[i][j]);
        res = max(res,rockClimbing(i+1,j+1) + mat[i][j]);
        return dp[i][j] = res;
    }
    else return 0;
}
main()
{
    memset(dp,-1,sizeof(dp));
    cout<<rockClimbing(0,0)<<endl;
}
