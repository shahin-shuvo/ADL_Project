#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2




int vertex,edge,node;
int color[50000];

std::vector<int>adj[100000];


void dfs(int src)
{
    color[src] = grey;
    for(int i =0; i<adj[src].size(); i++)
    {
        node = adj[src][i];
        if(color[node]==grey || color[node]==black) continue;
        if(color[node] == white)
            dfs(node);
    }
    color[src] = black;
}


main()
{

    int u,v,i,j,k,max_val,ind;
    int test_case;

    freopen("file","r",stdin);
    scanf("%d",&test_case);
    for(k=1; k<=test_case; k++)
    {


        scanf("%d",&vertex);
        for(i=0; i<vertex; i++)
        {
           scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        int mail[vertex+1]= {0};

        memset(color,0,sizeof(color));
        for(i=1; i<=vertex; i++)
        {
            dfs(i);
            for(j=1; j<=vertex; j++)
            {
                if(color[j]==grey || color[j]==black)
                {
                    mail[i]++;
                }
            }

        }
        max_val = -99999;
        ind =0;
        for(i=1; i<=vertex; i++)
        {
            if(mail[i]>max_val)
            {
                max_val = mail[i];
                ind =i;

            }
        }
        printf("Case : %d\n",ind);

        for(i=1; i<=vertex; i++) adj[i].clear();
    }
}
