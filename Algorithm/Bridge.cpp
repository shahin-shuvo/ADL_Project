#include<bits/stdc++.h>
using namespace std;
#define max 10000

struct articulation
{
    int vertex,edge,time;
    vector<int>adj[max];
    bool arti[max];
    int dis[max],fin[max],vis[max],parent[max],low[max];
    set<pair<int,int> >bridge;

    void initializer()
    {
        time = 0;
        memset(dis,0,sizeof(dis));
        memset(fin,0,sizeof(fin));
        memset(vis,-1,sizeof(vis));
        memset(arti,false,sizeof(arti));
        memset(parent,-1,sizeof(parent));
        memset(low,9999999,sizeof(low));
    }

    void create_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int src)
    {
        int children = 0;
        vis[src]  = 1;
        dis[src] = ++time;
        low[src] = dis[src];
        for(int i = 0;i<adj[src].size();i++)
        {
            int node = adj[src][i];
            if(vis[node]!=1)
            {
                children++;
                parent[node] = src;
                dfs(node);
                low[src] = min(low[src],low[node]);
                if(low[node]> dis[src])
                {
                    //cout<<src<<" "<<node<<endl;
                   if(src<node) bridge.insert(make_pair(src,node));
                   else bridge.insert(make_pair(node,src));
                }

            }
            else if(node != parent[src])
                low[src] = min(low[src],dis[node]);
        }
        fin[src] = ++time;
    }

};

main()
{
    int i,u,v;
    articulation ap;
    freopen("file","r",stdin);
    cin>>ap.vertex>>ap.edge;
    for(i=0;i<ap.edge;i++)
    {
        cin>>u>>v;
        ap.adj[u].push_back(v);
        ap.adj[v].push_back(u);
    }
    ap.initializer();
    ap.bridge.clear();
    for(i=0;i<ap.vertex;i++)
    {
        if(ap.vis[i]!=1)
        {
            ap.dfs(i);
        }
    }
    pair<int,int> p;
    cout<<"Bridge:"<<endl;
    for(set<pair<int, int> > ::iterator it = ap.bridge.begin(); it != ap.bridge.end();it++)
    {
        p = *it;
        cout<<p.first<<" "<<p.second<<endl;
    }

}

