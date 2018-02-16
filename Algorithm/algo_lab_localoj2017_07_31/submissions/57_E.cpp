#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2

struct Edge
{
    int u;
    int v;
    char type;
};
struct scc
{
    int vertex,edge,node;
    int color[5000];
    int dis[5000];
    int fin[5000];
    Edge edge_array[5000];
    int time,k=0;
    stack<int>top;
    vector<int>adj[5000];


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
            if(color[node]==black )
            {
                if(dis[src]<dis[node])
                {
                    edge_array[k].u=src;
                    edge_array[k].v=node;
                    edge_array[k].type='F';
                    k++;

                }
                else
                {
                    edge_array[k].u=src;
                    edge_array[k].v=node;
                    edge_array[k].type='C';
                    k++;

                }
            }
            if(color[node]==grey)
            {
                edge_array[k].u=src;
                edge_array[k].v=node;
                edge_array[k].type='B';
                k++;

            }
            if(color[node]==white)
            {
                edge_array[k].u=src;
                edge_array[k].v=node;
                edge_array[k].type='T';
                k++;

                dfs(node);
            }

        }

        time = time+1;
        fin[src] = time;
        color[src] = black;


    }
    void _sort(){
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k;j++)
        if(edge_array[j].u<edge_array[i].u)
        {

            swap(edge_array[j],edge_array[i]);
        }
        else if(edge_array[j].u==edge_array[i].u)
        {
             if(edge_array[j].v<edge_array[i].v)
             {
                 swap(edge_array[j],edge_array[i]);
             }
        }
    }
    }
    void print()
    {
        for(int i=0;i<k;i++)
        {
            cout<<edge_array[i].u<<" "<<edge_array[i].v<<" "<<"("<<edge_array[i].type<<")"<<endl;
        }
    }
};

main()
{
    scc s;
    int u,v,i;
    int component;

    cin>>s.vertex>>s.edge;
    for(i=0; i<s.edge; i++)
    {
        cin>>u>>v;
        s.insert_(u,v);
    }
    for(i=0; i<s.edge; i++)
    {
        sort(s.adj[i].begin(),s.adj[i].end());
    }

    s.init();
    for(i=0; i<s.vertex; i++)
    {
        if(s.color[i]==white)
            s.dfs(i);
    }
    s._sort();
    s.print();



}
