#include<bits/stdc++.h>
using namespace std;
#define max 100

vector<int>adj[max],cost[max];
int dist[max],path[max],n;

struct node
{
    int distance,vertex;
    bool operator <(const node &a) const
    {
        return distance<a.distance;
    }

};

priority_queue<node>pq;

void dijkstra(int src)
{
    node nd;
    nd.vertex = src;
    nd.distance =0;
    dist[src]  =0;
    pq.push(nd);

    while(!pq.empty())
    {
        nd =  pq.top();
        pq.pop();
        int s = nd.vertex;
        int dis = nd.distance;

        for(int i =0;i< adj[s].size();i++)
        {
            if((dist[s]+cost[s][i])<dist[adj[s][i]])
            {
                dist[adj[s][i]] = dist[s]+cost[s][i];
                nd.vertex = adj[s][i];
                nd.distance = dist[adj[s][i]];
                pq.push(nd);
                path[adj[s][i]] = s;
            }
        }
    }
}

void shortest_path(int s)
{
    if(path[s]==-1) printf("%d is source\n",s);
    else
    {
        printf("Shortest path of %d : ",s);
        while(path[s]!=-1)
        {
            printf("%d ",path[s]);
            s = path[s];
        }
        puts("");
    }
}

int main()
{
    int m,x,y,w,i;
    for(i=0; i<max; i++) dist[i] = INT_MAX;
    memset(path,-1,sizeof(path));
    freopen("file","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        adj[x].push_back(y);
        adj[y].push_back(x);
        cost[x].push_back(w);
        cost[y].push_back(w);
    }
    dijkstra(1);
    puts("");
    for(i=1; i<=n; i++)
    {
        printf("Length of shortest path of %d = %d\n",i,dist[i]);
        shortest_path(i);
        puts("");
    }
    return 0;
}
