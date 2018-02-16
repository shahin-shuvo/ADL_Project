#include<bits/stdc++.h>
using namespace std;

#define inf -100
#define nil -1
#define white 0
#define red 1
#define blue 2


struct breadth
{
    vector < int > adj[300];
    int node,edge;
    int color[300],prev[300],l[300];

    bool bicoloring(int src)
    {
        int i,u;

        memset(color,white,sizeof(color));

        color[src]=red;

        queue < int > q;
        q.push(src);

        while(!q.empty())
        {
            int t = q.front();
            q.pop();

           for(i=0;i<adj[t].size();i++)
            {
                u=adj[t][i];
                if(color[u]==white)
                {
                    if(color[t]==red)
                        color[u]=blue;
                    else
                        color[u]=red;
                    q.push(u);
                }
                if(color[t]==color[u])
                    return false;
            }

        }
        return true;
    }

};

int main()
{
    breadth ds;
    int i,j,a,b,u,v,e;
    int no;
    while(1)
    {
        cin>>no;
        if(no==0)
        {
            break;
        }
        cin>>e;
        memset(ds.adj,0,sizeof(ds.adj));
        for(i=1; i<=e; i++)
        {
            cin>>u>>v;
            ds.adj[u].push_back(v);
        }
        if(ds.bicoloring(0))
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }


    return 0;
}
