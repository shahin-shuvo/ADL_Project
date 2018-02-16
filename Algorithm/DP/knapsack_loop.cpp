#include<bits/stdc++.h>
using namespace std;

int main()
{

    int dp[100][100];
    memset(dp, -6575, sizeof(dp));
    dp[0][0] = 0;
    int capacity = 5;

    int weight[100],value[100];

    weight[1] = 2;
    weight[2] = 1;
    weight[3] = 3;
    weight[4] = 2;
    value[1] = 12;
    value[2] = 10;
    value[3] = 20;
    value[4] = 15;

    for(int i = 0; i<=4; i++)
    {
        for(int j = 0; j<=capacity; j++)
        {
            if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
            else{

            if(j>=weight[i])
            {
                dp[i][j] = max(dp[i-1][j], value[i] + dp[i-1][j-weight[i]]);
            }

            else
            {
                dp[i][j] = dp[i-1][j];
            }
            }
        }

    }

    for(int i = 0; i<=5; i++)
    {

        for(int j = 0; j<=capacity; j++)
        {
            cout<<dp[i][j]<<" ";

        }

        puts("");
    }


}
