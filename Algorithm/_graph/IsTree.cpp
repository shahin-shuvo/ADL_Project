#include<bits/stdc++.h>
using namespace std;

#define white 0
#define grey 1
#define black 2

vector<int> adj[100];
vector<int> topsort;

int vis[100], dis[100], parent[100];
int indegree[100], color[100];
bool binary = true;
int outdegree[100];

bool isCycle;

int node, edge;

void init()
{
    memset(indegree, 0, sizeof indegree);
    memset(outdegree, 0, sizeof outdegree);
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
        //adj[v].push_back(u);
        ++indegree[v];
        ++outdegree[u];
    }
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
    binary = true;
    for(int i=1; i<=node; i++)
    {
        if(indegree[i]==0)
        {
            root = i;
            cnt++;
        }
        if(outdegree[i]>2)
        {
            binary = false;
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
int main()
{
    init();
    input();
    isTree();
    if(binary == false) cout<<" Not Binary "<<endl;
    else cout<<"Binary "<<endl;
}


