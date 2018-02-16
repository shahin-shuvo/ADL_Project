#include<bits/stdc++.h>
using namespace std;

#define SZ 1002
#define inf 1009

struct vertex{
    int in;
    int val;
}ver;

struct Edge{
    int u;
    int v;
    int val;

    bool operator<(const Edge &ob)const{
        return val>ob.val;
    }
}ed;


struct minimum_spaning_tree{
    int node,edge;
    int dis[SZ];
   // int cost[SZ][SZ];
    int prev[SZ];
    bool vis[SZ];

    vector<vertex>vec[SZ];
    vector<vertex>tree[SZ];
    priority_queue<Edge>pq;

    void spaning(int src){

        int i,j,k;
        vis[src]=true;

        for(i=0;i<vec[src].size();i++)
        {
            ver=vec[src][i];
            if(vis[ver.in]==true)
                continue;
            ed.u=src;
            ed.v=ver.in;
            ed.val=ver.val;
            pq.push(ed);

        }

        while(1){
            if(pq.empty())
                return;
            ed=pq.top();

            pq.pop();
            if(vis[ed.v]==false){
                break;
            }

        }

        ver.in=ed.v;
        ver.val=ed.val;
        tree[ed.u].push_back(ver);
        ver.in=ed.u;
        tree[ed.v].push_back(ver);
        cout<<ed.v<<endl;
        spaning(ed.v);
    }

};


int main()
{
    int i,j,u,v,w,k,cost=0;

    minimum_spaning_tree mst;
    cin>>mst.node>>mst.edge;

    for(i=1;i<=mst.edge;i++){
        cin>>u>>v>>w;
        ver.in=v;
        ver.val=w;
        mst.vec[u].push_back(ver);
        ver.in=u;
        mst.vec[v].push_back(ver);
    }


    for(i=1;i<=mst.node;i++){
        mst.vis[i]=false;
    }

    mst.spaning(1);

    for(i=1;i<=mst.node;i++)
    {
        cout<<i<<"th node's edges are ";

        for(j=0;j<mst.tree[i].size();j++)
        {
            cout<<mst.tree[i][j].in<<" "<<mst.tree[i][j].val<<endl;
            cost+=mst.tree[i][j].val;
        }
        cout<<endl;
    }

    cout<<"Minimum cost is : "<<cost/2<<endl;

    return 0;
}


