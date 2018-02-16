#include<bits/stdc++.h>
using namespace std;
#define max 100

struct BFS
{
    int vertex,edge;
    int flag;
    vector<int>List[max];
    int mat[max][max];
    int vis[max],level[max];
    int parent[max];
    BFS()
    {
        memset(level,-1,sizeof(level));
        memset(vis,0,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        flag = 0;
    }

    // Insert into Adjacency matrix
    void insert_mat(int u,int v)
    {
        mat[u][v] = 1;
        mat[v][u]= 1;
    }
    //insert into Adjacency List
    void insert_list(int u,int v)
    {
        List[u].push_back(v);
        List[v].push_back(u);
    }
    // Check the edge by Matrix
    int checkAdjMat(int u,int v)
    {
        if(mat[u][v]==1)
            return 1;
        else return -1;
    }
    //Check the edge by List
    int checkList(int u,int v)
    {
        for(int i = 0; i<List[u].size(); i++)
        {
            if(List[u][i]==v)
                return 1;
        }
        return -1;
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
                    parent[List[p][i]] = p;
                }
            }

        }
    }
    int hasPath(int u,int v)
    {
        bfs(u);
        if(level[v]==-1)
            return -1;
        else return 1;
    }

    void printShortestPath(int parent[],int v)
    {
        if(parent[v]==-1)
            return;
        printShortestPath(parent,parent[v]);
        cout<<v<<" ";
    }


    int shortestPath(int u,int v)
    {
        bfs(u);
        return level[v];
    }

    void IsBipartite(int source)
    {
        queue<int>q;
        q.push(source);

        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            for(int i=0; i<List[p].size(); i++)
            {
                if(vis[List[p][i]]==0)
                {
                    vis[List[p][i]]=1;
                    level[List[p][i]]=level[p]+1;
                    q.push(List[p][i]);
                }
                else
                {
                    if(level[p]%2==level[List[p][i]]%2)
                    {
                        flag=1;
                        return ;
                    }
                }
            }
        }

    }


};
main()
{
    BFS b;
    int i,u,v;
    memset(b.mat,0,sizeof(b.mat));
    cin>>b.vertex>>b.edge;
    for(i=1; i<=b.edge; i++)
    {
        cin>>u>>v;
        b.insert_mat(u,v);
        b.insert_list(u,v);
    }
    cout<<"1 for check with matrix."<<endl;
    cout<<"2 for check with list."<<endl;
    cout<<"3 for has path?"<<endl;
    cout<<"4 for length of shortestPath"<<endl;
    cout<<"5 print the shortestPath"<<endl;
    cout<<"6 for check bipartite"<<endl;

    int choice;
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            cin>>u>>v;
            cout<<b.checkAdjMat(u,v)<<endl;
            break;
        case 2:
            cin>>u>>v;
            cout<<b.checkList(u,v)<<endl;
            break;
        case 3:
            cin>>u>>v;
            cout<<b.hasPath(u,v)<<endl;
            break;
        case 4:
            cin>>u>>v;
            cout<<b.shortestPath(u,v)<<endl;
            break;
        case 5:
            cin>>u>>v;
            cout<<u<<" ";
            b.bfs(u);
            b.printShortestPath(b.parent,v);
            cout<<endl;
            break;
        case 6:
            cin>>v;
            b.IsBipartite(v);
            if(b.flag) cout<<"Not Bicolor"<<endl;
            else cout<<"Colorable"<<endl;
            break;

        }
    }
}
