#include<bits/stdc++.h>
using namespace std;

struct BFS
{
    int vertex,edge;
    vector<int>List[10010];
    int vis[10010],level[10010];
    BFS()
    {
        memset(level,-1,sizeof(level));
        memset(vis,0,sizeof(vis));
    }

    void insert_list(int u,int v)
    {
        List[u].push_back(v);
        List[v].push_back(u);
    }



    void bfs(int source)
    {
        queue<int>q;
        q.push(source);
        level[source] = 0;


        while(!q.empty())
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
    int i,u,v,test;
    cin>>test;
    while(test--)
    {

    cin>>b.vertex>>b.edge;
    for(i=1; i<=b.edge; i++)
    {
        cin>>u>>v;
        b.insert_list(u,v);
    }
    b.bfs(0);
    for(i=1;i<b.vertex;i++)
        cout<<b.level[i]<<endl;
     if(test!=0)  cout<<endl;
    }



}
