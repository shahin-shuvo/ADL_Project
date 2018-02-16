
#include<bits/stdc++.h>
using namespace std;

#define SZ 1000
#define inf 100000

struct Vertex{
    int index;
    int cost;
};


struct belman{
    int node,edge;
    int vis[SZ],dis[SZ];
    int cost[SZ][SZ];
    Vertex vertex;

    vector<int>vec[SZ];

    bool ford(int src){
        int i,j;

        for(i=0;i<node;i++){
            dis[i]=inf;
        }

        dis[src]=0;

        for(i=0;i<node;i++){
            for(j=0;j<node;j++){

            }
        }
    }
};


int main()
{
    int i,j,u,v,w;
    belman bel;
    Vertex vertex;

    cin>>bel.node>>bel.edge;

    for(i=0;i<bel.edge;i++){
        cin>>u>>v>>w;
        vertex.index=v;
        vertex.cost=w;
        bel.vec[u].push_back(vertex);
    }


}
