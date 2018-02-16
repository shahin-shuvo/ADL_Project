#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int  parent[101],coun;
bool cycle;
char vis[101];
int edge, vertex;
stack<int> st;

void reset()
{

    for(int i=0; i<101; i++)
    {
        vis[i] = 'W';
        parent[i]=-1;
    }

    cycle = false;
}



void dfs(int u)
{
    vis[u]='G';
    for(auto &x: adj[u])
    {
        if(vis[x]=='G')
        {
            parent[x]=u;
            cycle = true;
            coun++;
            //return;
        }
        else if(vis[x]=='W') dfs(x);
    }
    st.push(u);
    vis[u]='B';
}

/*void printShortestPath()
    {
        if(parent[v]==-1)
            return;
        printShortestPath(parent,parent[v]);
        cout<<v<<" ";
    }*/

main()
{
    reset();
    int u,v;
    cin>>edge>>vertex;
    for(int i = 0; i<vertex; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    puts("\t\t  1. Press 1 to find topological order of graph. && cyclic");
    puts("\t\t  2. Press 2 to find tree or not.");
    int choice;
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            for(int i=1; i<=vertex; i++)
            {
                if(vis[i]=='W') dfs(i);
            }
            if(cycle)
            {
                printf("Cycle present\n");
                printf("Cycle : %d\n",coun);

            }
            else
            {
                printf("The required order is: ");
                while(!st.empty())
                {
                    printf("%d ", st.top());
                    st.pop();
                }
                puts("");
            }
            break;
        case 2:
            int cmp=0;
            cycle = false;
            for(int i=1; i<=vertex; i++)
            {
                if(vis[i]=='W')
                {
                    dfs(i);
                }
            }

            reset();
            cycle = false;
            while(!st.empty())
            {
                int x = st.top();
                st.pop();
                if(vis[x]=='W')
                {
                    cmp++;
                    dfs(x);
                }
            }

            if(cmp==1 && !cycle) printf("The graph is a tree\n");
            else printf("The graph is not a tree\n");
            break;
        }
    }
}
