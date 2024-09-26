#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

const long long int  N = 1005;
vector<pi> v[N];
bool vist[N];
long long int  dist[N];

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    dist[s] = 0;

    while (!pq.empty())
    {
        pair<int,int> parent = pq.top();
        pq.pop();

        int parentNode = parent.second;
        if(vist[parentNode]) continue;
        
        vist[parentNode] = true;
        int parentCost = parent.first;

        for (int i = 0; i < v[parentNode].size(); i++)
        {
            pair<int,int> child = v[parentNode][i];
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dist[childNode]){
                dist[childNode] = parentCost + childCost;
                pq.push({dist[childNode],childNode});
            }
        }
        
    }
    
}
int main(){ 
    long long int  n,e;
    cin>>n>>e;
    while (e--)
    {
        long long int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
    }

    for (long long int i = 1; i <= n; i++)
    {
        dist[i] = 1e9+7;
    }
    long long int  s;
    cin>>s;
    dijkstra(s);
    long long int  t;
    cin>>t;
    while (t--)
    {
        long long int  d,dw;
        cin>>d>>dw;
        if(dist[d] <= dw) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}