#include<bits/stdc++.h>
using namespace std;

#define white 0
#define grey 1
#define black 2

struct Graph
{

    vector<int> adj[100];
    vector<int> topsort;

    int vis[100], dis[100], parent[100];
    int indegree[100], color[100];

    bool isCycle;

    int node, edge;

    void init()
    {
        memset(indegree, 0, sizeof indegree);
        memset(parent, -1, sizeof parent);
        memset(vis, 0, sizeof vis);
        for(int i = 0; i<100; i++) adj[i].clear();
    }

    void input()
    {
        init();

        cin>>node>>edge;

        for(int i=0; i<edge; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            //  adj[v].push_back(u);
            ++indegree[v];
        }
    }

    void print_list()
    {
        for(int i=1; i<=node; i++)
        {
            cout<<i<<" -> ";
            for(auto x:adj[i])  cout<<x<<" ";
            puts("");
        }

    }

//    void print_path(int src, int dst)

    // finding shortest path and path printing

    void bfs_util(int src, int dst)
    {
        memset(dis, -1, sizeof dis);
        bfs(src, dst);
    }

    // finding shortest path and path printing

    void bfs(int src, int dst)
    {
        dis[src] = 0;
        parent[src] = -1;

        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            for(int i=0; i<adj[top].size(); i++)
            {
                int v = adj[top][i];

                if(dis[v]==-1)
                {
                    dis[v] = dis[top] +1;
                    parent[v] = top;
                    q.push(v);
                }
            }
        }

        int i = dst;
        while(i!=-1)    cout<<i<<" ", i = parent[i];
        cout<<"\n";

    }


    // topological sort

    void topsort_util()
    {
        memset(vis, 0, sizeof(vis));
        topsort.clear();

        // check korte hobe cycle ache ki na

        for(int i=1; i<=node; i++)
        {
            if(indegree[i]==0)  dfs(i);
        }

    }

    void dfs(int u)
    {
        vis[u] = 1;

        for(auto x:adj[u])
        {
            if(!vis[x]) dfs(x);
        }

        topsort.push_back(u);
    }


    void detect_cycle(int node)
    {

        color[node] = grey;

        for(int i=0; i<adj[node].size(); i++)
        {
            int u = adj[node][i];

            if(color[u]==grey)  isCycle = true;

            if(color[u]==black) continue;

            if(color[u]==white) detect_cycle(u);
        }

        color[node] = black;
    }

    void isCyclic()
    {

        // ei kaj ta shob node er jonno kora lagbe
        isCycle = false;
        memset(color, 0, sizeof color);
        detect_cycle(1);

        cout<<(isCycle?"Cycle ache":"cycle nai");
    }

    void isTree()
    {
        int cnt = 0, root;

        for(int i=1; i<=node; i++)
        {
            if(indegree[i]==0)
            {
                root = i;
                cnt++;
            }
        }

        if(cnt!=1)
        {
            cout<<"Not tree"<<endl;
            return;
        }

        isCycle = false;
        memset(color, 0, sizeof color);
        detect_cycle(root);

        if(isCycle==true)
        {
            cout<<"Not tree"<<endl;
            return;
        }

        for(int i=1; i<=node; i++)
        {
            if(color[i]!=black)
            {
                cout<<"Not tree"<<endl;
                return;
            }
        }

        cout<<"Tree :) "<<endl;
    }

    // flood fill

    // graph coloring

    // checking if a graph is a tree

};

int main()
{
    Graph g;

    g.input();

    //  g.topsort_util();

    //  g.

   // g.isCyclic();

   g.isTree();





    return 0;
}
