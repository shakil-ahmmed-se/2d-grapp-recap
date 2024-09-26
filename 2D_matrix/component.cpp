#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
int dist[N];
bool vis[N];
vector<int> cmp;

void dfs(int s){
    vis[s] = true;
    cmp.push_back(s);
    for(int child : v[s]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int component  = 0;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            component++;
            dfs(i);
            cout<<"component of "<<i<<" :";
            for(int val :cmp){
                cout<<val<<" ";
            }
            cout<<endl;
            cmp.clear();
        }
    }
    // cout<<component<<endl;
    
    return 0;
}