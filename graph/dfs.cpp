#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool vis[N];
vector<int> v[N];
int dist[N];

void dfs(int src){
    vis[src] = true;
    cout<<src<<endl;
    for (int i = 0; i < v[src].size(); i++)
    {
        int child = v[src][i];
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
    dfs(1);
    return 0;
}