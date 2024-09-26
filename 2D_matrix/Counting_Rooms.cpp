#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int n,m;
const int N = 1005;
bool vis[N][N];
char a[N][N];
vector <pi> path = {{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int cI,int cJ){
    if(cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] =='.')return true;
    else return false; 
}
void dfs(int si ,int sj){
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int cI = si+ p.first;
        int cJ = sj + p.second;
        if(isValid(cI,cJ) && !vis[cI][cJ]){
            // vis[]
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
    int component = 0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
            if(!vis[i][j] && a[i][j] == '.'){
                component++;
                dfs(i,j);
            }
       }
       
    }
   cout<<component<<endl;
    
    return 0;
}