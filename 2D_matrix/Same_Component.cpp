#include<bits/stdc++.h>
using namespace std;
#define  pi pair<int,int> 
const int N = 1005;
vector<pi>v[N][N];
bool vist[N][N];
char a[N][N];
int n,m;

vector<pi> path = {{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int cI,int cJ){
    if(cI>= 0 && cI< n && cJ >= 0 && cJ < m && a[cI][cJ] == '.') return true;
    else return false;
}
void bfs(int si,int sj){
    queue<pi> q;
    q.push({si,sj});
    vist[si][sj] =true;

    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pi child = path[i];
            int cI = pI +  child.first;
            int cJ = pJ + child.second;
            if(isValid(cI,cJ) && !vist[cI][cJ]){
                vist[cI][cJ] = true;
                q.push({cI,cJ});

            }
        }
        

    }
    
}
int main(){
 
    cin>>n>>m;
   
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
    int di,dj;
    cin>>di>>dj;
    
    if(vist[di][dj]){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}