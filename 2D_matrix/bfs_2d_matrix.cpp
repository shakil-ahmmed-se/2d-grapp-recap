#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int N = 1005;
bool vis[N][N];
int dist[N][N];
int n,m;

bool isValid(int cI,int cJ){
    if(cI >= 0 && cI < n &&  cJ>= 0 && cJ < m){
        return true;
    }
    else{
        return false;
    }
}
vector<pi> path = {{-1,0},{1,0},{0,-1},{0,1}};

void bfs(int si,int sj){
    queue<pi> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;
    while (!q.empty())
    {
        pi parent =q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            
            if(isValid(cI,cJ) && !vis[cI][cJ]){
                vis[cI][cJ] = true;
                q.push({cI,cJ});
                dist[cI][cJ] = dist[pI][pJ] + 1;
            }
            
        }
    }
    
    
}
int main(){
   
    cin>>n>>m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}