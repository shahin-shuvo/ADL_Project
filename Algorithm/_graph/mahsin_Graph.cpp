#include<bits/stdc++.h>
using namespace std;

int adj[1000][1000];
int vertex, edge;
void matIn(int u , int v){
    adj[u][v] = 1;
}
bool checkMat(int u , int v){
    if(adj[u][v])
        return true;
    else return false;
}

vector<int> adjList[1000];
int vis[1000], dis[1000];

bool checkList(int u , int v){
    for(int i=0; i<adjList[u].size(); i++){
        if(adjList[u][i]==v)
            return true;
        }
        return false;
}

void BFS(int s){
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(dis));
    queue <int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0; i<adjList[p].size(); i++){
            if(vis[adjList[p][i]]==false){
                dis[adjList[p][i]] = dis[p]+1;
                q.push(adjList[p][i]);
                vis[adjList[p][i]] = true;
            }
        }
    }
}

bool haspath(int u, int v){
    BFS(u);
    if(dis[v]==-1)  return false;
    else return true;
}

int shortestPath(int u, int v){
    BFS(u);
    return dis[v];
}

int main(){
    memset(adj,0,sizeof(adj));
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(dis));

    int u , v, i;

    cin>>vertex>>edge;
    for(i=0; i<edge; i++){
        cin>>u>>v;
        matIn(u, v);
        adjList[u].push_back(v);
    }

    int op;
    cin>>op;
    while(op){
        if(op==1){
            cin>>u >>v;
            cout<<checkMat(u,v);

        }
        if(op==2){
            cin>>u >>v;
            cout<<checkList(u,v);

        }
        if(op==3){
            cin>>u >>v;
            cout<<haspath(u,v);
        }
        if(op==4){
            cin>>u >>v;
            cout<<shortestPath(u,v);
        }
        cin>>op;
    }

}
