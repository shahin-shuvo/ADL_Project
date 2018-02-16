#include<bits/stdc++.h>
using namespace std;

int adj[1000][1000];
int vertex,edge;
vector<int>List[1000];

void MatInsert(int u,int v)
{
    adj[u][v] = 1;
}

void adjListInserts(int u,int v)
{
    List[u].push_back(v);
}

int checkAdjMat(int u,int v)
{
    if(adj[u][v]==1)
        return 1;
    else return -1;
}

int checkList(int u , int v){
    for(int i=0; i<List[u].size(); i++){
        if(List[u][i]==v)
            return 1;
        }
    return -1;
}

 main(){
    memset(adj,0,sizeof(adj));

    int u , v, i;

    cin>>vertex>>edge;
    for(i=0; i<edge; i++){
        cin>>u>>v;
        MatInsert(u, v);
        adjListInserts(u,v);
    }

    int choice;
    while(choice){
        cin>>choice;
        if(choice==1){
            cin>>u >>v;
            cout<<checkAdjMat(u,v)<<endl;

        }
        else if(choice==2){
            cin>>u >>v;
            cout<<checkList(u,v)<<endl;

        }
       /* else if(choice==3){
            cin>>u >>v;
            cout<<haspath(u,v);
        }
        else if(choice==4){
            cin>>u >>v;
            cout<<shortestPath(u,v);
        }*/
    }

}

