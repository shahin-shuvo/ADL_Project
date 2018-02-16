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
    int desc[100];
    int time,k=0;
    vector<int>adj[100];
    vector<int>rev[100];

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
    void insert_reverse(int u,int v)
    {
        rev[v].push_back(u);
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
        }

        time = time+1;
        fin[src] = time;
        color[src] = black;
        desc[k++]=src;

    }
    void dfs_rev(int src)
    {
        time = time+1;
        dis[src]=time;
        color[src] = grey;
        for(int i =0; i<rev[src].size(); i++)
        {
            node = rev[src][i];
            if(color[node] == white)
                dfs(node);
        }

        time = time+1;
        fin[src] = time;
        color[src] = black;
        desc[k++]=src;

    }
};
main()
{
    scc s;
    int u,v,i,j;
    int component=0;
    cin>>s.vertex>>s.edge;
    for(i=0; i<s.edge; i++)
    {
        cin>>u>>v;
        s.insert_(u,v) ;
        s.insert_reverse(u,v);
    }
    s.init();
    for(i=1; i<=s.vertex; i++)
    {
        if(s.color[i]==white)
             s.dfs(i);
    }

    for(i=1; i<=s.vertex; i++)
    {
        cout<<"vertex: "<<i<<" "<<"discovery: "<< s.dis[i] << " "<<"finishing: " << s.fin[i]<<endl;
    }
    cout <<"Decreasing order of finishing time : ";
    for(i=0;i<s.k;i++)
    {
        cout<<s.desc[i]<<" ";
    }
    cout<<endl;
    s.init();
    for(i=s.k-1; i>=0; i--)
    {
        int x = s.desc[i];
        if(s.color[x]==white)
        {
            component++;
             s.dfs_rev(i);

        }

    }
    cout<<"Component: "<<component<<endl;
}
