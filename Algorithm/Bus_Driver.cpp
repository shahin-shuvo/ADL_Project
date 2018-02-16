#include<bits/stdc++.h>
using namespace std;

bool ascending(int a,int b){
    return a<b;
}
bool descending(int a,int b){
    return a>b;
}

int main(){

   int n,d,r;
   //freopen("bus","r",stdin);
   //freopen("out","w",stdout);
    while(cin>>n>>d>>r && n && d && r){
        int morning[n],evening[n];
        for(int i=0;i<n;i++){
            cin>>morning[i];
        }
        for(int i=0;i<n;i++){
            cin>>evening[i];
        }
        sort(morning,morning+n,ascending);
        sort(evening,evening+n,descending);

        int temp2=0;
        int t=0;
        for(int i=0;i<n;i++){
            int temp=(d-(morning[i]+evening[i]));
            if(temp<0){
                t=temp*r*-1;
                temp2=temp2+t;
            }


        }
        cout<<temp2<<endl;
    }
}
