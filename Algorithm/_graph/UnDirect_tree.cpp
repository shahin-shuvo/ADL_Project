#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,bool> Links;
    int n,m,N1,N2;

    cin>>n>>m;
    if(m!=n-1) //First Condition: Number of Links=Number of Nodes-1
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while(m!=0)
    {
        m--;
        cin>>N1>>N2;

        if(Links[N1] && Links[N2]) //Asumming the graph is given as it builds
        {
            cout<<"NO"<<endl;
            return 0;
        }
       Links[N1]=1;
       Links[N2]=1;
    }


    cout<<"YES"<<endl;

    return 0;
}
