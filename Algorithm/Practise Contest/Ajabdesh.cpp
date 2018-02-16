#include<bits/stdc++.h>
using namespace std;


#define white 0
#define grey 1
#define black 2


struct breadth
{
    vector < int > v[10000];
    int node,edge,u;
    int color[200];

    bool bicoloring(int src)
    {
        int i;

        memset(color,0,sizeof(color));

        color[src]=grey;

        queue < int > q;
        q.push(src);

        while(!q.empty())
        {
            int t = q.front();
            q.pop();

           for(int i =0;i<v[t].size();i++)
            {
                int u = v[t][i];
                if(color[u]==white)
                {
                    if(color[t]==grey)
                        color[u]=black;
                    else
                        color[u]=grey;
                    q.push(u);
                }
                if(color[t]==color[u])
                    return false;
            }

        }
        return true;
    }
    void dfs(int src)
    {

        color[src] = grey;
        for(int i =0; i<v[src].size(); i++)
        {
            u = v[src][i];
            if(color[u] == white)
                dfs(u);
        }


        color[src] = black;


    }

};

int main()
{
    breadth ds;
    int i,j,a,b,u,v,test;
    freopen("file","r",stdin);
    cin>>test;
    for(j=0;j<test;j++)
    {

    cin>>ds.node>>ds.edge;

    for(i=0;i<ds.edge;i++)
    {
        cin>>a>>b;
        ds.v[a].push_back(b);
        ds.v[b].push_back(a);

    }

    int coun=0;

    for(i=0;i<ds.node;i++)
    {
        if(ds.color[i]==white)
        {
            coun++;
            cout<<"IN "<<i<<endl;
            ds.dfs(i);
        }

    }
    bool bi=ds.bicoloring(0);

    if(bi==true)
         cout<<coun<<endl;
    else
        cout<<-1<<endl;
    for(i=1; i<ds.node; i++) ds.v[i].clear();
    }



    return 0;
}

