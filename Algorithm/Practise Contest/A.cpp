#include <bits/stdc++.h>
using namespace std;

class Graph_{

    int numVertices;
    vector<int> *adjList;
    int* parent;

    public: Graph_(int vertices){

        numVertices = vertices;
        adjList = new vector<int>[vertices];
    }

    void add_edge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }


    void bfs(int source){
        int level[numVertices];
        int parent[numVertices];
         memset(level,-1,sizeof(level));

        queue<int> q;
        level[source] = 0;
        parent[source] = -1;
        q.push(source);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i = 0; i<adjList[u].size(); i++){
                if(level[adjList[u][i]] == -1){
                    int v = adjList[u][i];
                    level[v] = level[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        int i = 1;
        for(i; i< numVertices; i++ ){
        printf("%d\n", level[i]);
    }
    }


};

int main(){

    int cases;
    scanf("%d", &cases);

    while(cases--){
     int n, no_of_input;
     scanf("%d %d", &n, &no_of_input);
     Graph_ g(n);

     for(int i =0; i<no_of_input; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        g.add_edge(u,v);
     }

     g.bfs(0);
     if(cases != 0){
        printf("\n");
     }

    }

}
