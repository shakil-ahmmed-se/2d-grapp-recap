#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
int dst[N];
bool vis[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dst[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout<<parent<<endl;

        //children ber korar jonno
        for (int i = 0; i <v[parent].size(); i++)
        {
            int child = v[parent][i];
            if(vis[child] == false){
                q.push(child);
                dst[child] = dst[parent] +1;
                vis[child] = true;

            }
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
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout<<"Node "<<i<<" : "<<dst[i]<<endl;
    }
    
    return 0;
}