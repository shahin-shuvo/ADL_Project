#include<bits/stdc++.h>
using namespace std;
#define max 1000
#define inf 1009

struct vertex
{
    int node;
    int cost;
} ver;

struct Edge
{
    int u;
    int v;
    int cost;
    bool operator<(const Edge &ob)const
    {
        return cost>ob.cost;
    }
}edge;

struct MST
{
    int node,edgeno;
    int dis[max];
    int prev[max];
    bool vis[max];

    vector<vertex>vec[max];
    vector<vertex>tree[max];
    priority_queue<Edge>pq;

    void spanning_tree(int src)
    {
        vis[src] = true;

        for(int i=0; i<vec[src].size(); i++)
        {
            ver = vec[src][i];
            if(vis[ver.node]==true)
                continue;
            edge.u=src;
            edge.v=ver.node;
            edge.cost = ver.cost;
            pq.push(edge);
        }

    while(1)
    {
        if(pq.empty())
            return;
        edge=pq.top();

        pq.pop();
        if(vis[edge.v]==false)
        {
            break;
        }

    }
    ver.node=edge.v;
    ver.cost=edge.cost;
    tree[edge.u].push_back(ver);
    ver.node=edge.u;
    tree[edge.v].push_back(ver);
    cout<<edge.v<<endl;
    spanning_tree(edge.v);
    }

};
int main()
{
    int i,j,u,v,w,k,cost=0;

    MST mst;
    freopen("file","r",stdin);
    cin>>mst.node>>mst.edgeno;

    for(i=1;i<=mst.edgeno;i++){
        cin>>u>>v>>w;
        ver.node=v;
        ver.cost=w;
        mst.vec[u].push_back(ver);
        ver.node=u;
        mst.vec[v].push_back(ver);
    }


    for(i=1;i<=mst.node;i++){
        mst.vis[i]=false;
    }

    mst.spanning_tree(1);

    for(i=1;i<=mst.node;i++)
    {
        cout<<i<<"th node's edges are ";

        for(j=0;j<mst.tree[i].size();j++)
        {
            cout<<mst.tree[i][j].node<<" "<<mst.tree[i][j].cost<<endl;
            cost+=mst.tree[i][j].cost;
        }
        cout<<endl;
    }

    cout<<"Minimum cost is : "<<cost/2<<endl;

    return 0;
}
