#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2


struct scc
{
    int vertex,edge,node;
    int color[100];
    int dis[100];
    int fin[100];

    int time,k=0;
    stack<int>top;
    vector<int>adj[100];
    bool cycle = false;

    void init()
    {
        time =0;
        memset(color,0,sizeof(color));
        memset(dis,0,sizeof(dis));
        memset(fin,0,sizeof(fin));
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
main()
{
    scc s;
    int u,v,i;
    int component;
    freopen("file","r",stdin);
    cin>>s.vertex>>s.edge;
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
    if(s.cycle) cout<<"Graph is cyclic , Topsort not possible"<<endl;
    else{
    cout <<"Topsort : ";
    while(!s.top.empty())
    {
        cout<<s.top.top()<<" ";
         s.top.pop();
    }
    cout<<endl;
    }
}
