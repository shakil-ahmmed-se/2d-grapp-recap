#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int N = 1005;
char a[N][N];
bool vist[N][N];

int n,m;
vector <pi> path = {{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int cI, int cJ) {
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}

int cnt  ;
void dfs(int si,int sj){
    vist[si][sj] = true;
    cnt++;
    // cout<<cnt<<endl;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int cI = si+ p.first;
        int cJ = sj + p.second;
        if(isValid(cI,cJ) && !vist[cI][cJ] && a[cI][cJ] =='.'){
            dfs(cI,cJ);
        }
    }
    
}
int main(){
    
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int minArea = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
           if(!vist[i][j] && a[i][j] == '.'){
                cnt = 0;
                dfs(i,j);
                minArea = min(minArea,cnt);
                
            }
            
        }
        
    }
   if (minArea == INT_MAX)
        cout << -1 << endl;
    else
        cout << minArea << endl;
    
   
    return 0;
}