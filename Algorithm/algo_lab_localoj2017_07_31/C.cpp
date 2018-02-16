
#include<bits/stdc++.h>
using namespace std;
#define max 100005

struct BFS
{
    int vertex,edge;
    int flag;
    vector<int>List[max];

    int vis[max],level[max];

    BFS()
    {
        memset(level,-1,sizeof(level));
        memset(vis,0,sizeof(vis));

    }


    //insert into Adjacency List
    void insert_list(int u,int v)
    {
        List[u].push_back(v);
        List[v].push_back(u);
    }

    // Breadth first Search
    void bfs(int source)
    {
        queue<int>q;
        q.push(source);
        level[source] = 0;


        while(!q.empty()) // WHILE queue is no empty
        {
            int p = q.front();
            q.pop();
            vis[p] = 1;

            for(int i = 0; i< List[p].size() ; i++)
            {
                if(vis[List[p][i]]==0)
                {

                    q.push(List[p][i]);
                    level[List[p][i]] = level[p]+1;
                    vis[List[p][i]] = 1;

                }
            }

        }
    }


};
main()
{
    BFS b;
    int i,u,v;
    //freopen("file","r",stdin);
    cin>>b.edge;
    for(i=0; i<b.edge; i++)
    {
        cin>>u>>v;

        b.insert_list(u,v);
    }
    int MAX=-9999;
    b.bfs(0);
    for(i=0;i<b.edge;i++)
    {
        if(b.level[i]>MAX)
            MAX=b.level[i];
    }
    int time ;
    time = 2*(b.edge-1)-MAX;
    cout<<time<<endl;

}
