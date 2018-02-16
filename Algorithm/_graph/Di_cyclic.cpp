#include<bits/stdc++.h>
using namespace std;

vector <int> adj[101];
stack<int>S;
int A[101][101];
bool visited[101];
int dist[100];
bool funcstack[100];
void initialize()
{
    for(int i=1; i<=101; i++)
        visited[i]=false;
}
void dfs(int s)
{
    visited[s] = true;
    S.push(s);
    //funcstack[s]=true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            cout<<s<<" ";
           dfs(adj[s][i]);
        }
    }
}

bool dfss(int nodes)
{
    for(int i = 1; i <= nodes; ++i)
    {
        if(visited[i] == false)
        {
            //if(dfs(i)==true)
                return true;
        }
    }
    return false;
}

int main()
{
    int nodes,edge,x,y,i;
    cout<<"Please...Enter the nodes and edges"<<endl;
    cin>>nodes>>edge;

    for(i=1; i<=edge; i++)
    {
        cin>>x>>y;
        A[x][y] = 1;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    initialize();
    cout<<"Enter the node where dfs started: ";
    cin>>x;
    dfs(x);
    return 0;
}

