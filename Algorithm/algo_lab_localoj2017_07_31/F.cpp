#include<bits/stdc++.h>
using namespace std;


struct depth
{
    int ara[100][100],n,vis[100],e,cnt=0;

    void dfs(int u)
    {
        vis[u]=1;

        for(int i=1;i<=n;i++)
        {
            if(ara[u][i]==1 && vis[i]==0)
            {
                 cnt++;
                 dfs(i);

            }

        }
    }
};


main()
{
    depth ds;
    int i,j,a,b,u,v;
    char mat[100][100];
    std:string line;
    char x;
    freopen("file","r",stdin);
    cin>>ds.n>>ds.e;

    for(i=0;i<=ds.n;i++)
    {
        getline(cin,line);

        for(j=0;j<ds.e;j++)
        {
            cout<<line[j];

            if(line[j]=='.')
            {
                ds.ara[i][j]=1;
            }
            else ds.ara[i][j] =0;
        }
        printf("\n");
    }

    memset(ds.vis,0,sizeof(ds.vis));

    for(i=1;i<=ds.n;i++)
    {
        for(j=1;j<=ds.e;j++)
        {
            //cin>>mat[i][j];
            //cout<<mat[i][j];
        }
        //printf("\n");
    }
    ds.dfs(2);
    cout<<ds.cnt<<endl;


}
