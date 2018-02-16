#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2


struct scc
{
    int vertex,edge,node;
    int color[1000];
    int dis[1000];
    int fin[1000];

    int time,k=0;
    stack<int>top;
    vector<int>adj[1000];
    bool cycle = false;

    void init()
    {
        time =0;
        cycle= false;
        memset(color,0,sizeof(color));
        memset(dis,0,sizeof(dis));
        memset(fin,0,sizeof(fin));
        for(int i=1; i<=vertex; i++) adj[i].clear();
    }
    void insert_(int u,int v)
    {
        adj[u].push_back(v);
    }


    void dfs(int src)
    {
        time = time+1;
        dis[src]=time;
        color[src] = grey;
        for(int i =0; i<adj[src].size(); i++)
        {
            node = adj[src][i];
            if(color[node] == white)
                dfs(node);
            else if(color[node] == grey)
            {
               cycle = true;
               return;
            }

        }

        time = time+1;
        fin[src] = time;
        color[src] = black;
        top.push(src);

    }
};
int main()
{
    scc s;
    int u,v,i;

    freopen("file","r",stdin);
    while( cin>>s.vertex!=0 &&  cin>>s.edge != 0)
    {
    for(i=0; i<s.edge; i++)
    {
        cin>>u>>v;
        s.insert_(u,v) ;
    }
    s.init();
    for(i=1; i<=s.vertex; i++)
    {
        if(s.color[i]==white)
             s.dfs(i);
    }
    if(!s.cycle)
    {
    while(!s.top.empty())
    {
        cout<<s.top.top();

         s.top.pop();
           if(s.top.size()>=1) cout<<" ";
           if(s.top.size()==0) cout<<endl;
    }

    }
    }
}

