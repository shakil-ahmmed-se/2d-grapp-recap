#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
const int N = 1005;
bool vis[N][N];
int dist[N][N];
int n,m;

vector<pi> path = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

bool isValid(int cI,int cJ){
    if(cI >= 0 && cI < n &&  cJ>= 0 && cJ < m){
        return true;
    }
    else{
        return false;
    }
}

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
        
        for (int i = 0; i < 8; i++)
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
    int t;
    cin>>t;
    while (t--)
    {
       
        cin>>n>>m;
        int ki,kj,qi,qj;
        cin>> ki>>kj>>qi>>qj;
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < m; j++)
           {
                dist[i][j] = -1;
                vis[i][j] = false;
                
           }
           
        }
        bfs(ki, kj);
        cout<<dist[qi][qj]<<endl;
    }

    
    
    return 0;
}