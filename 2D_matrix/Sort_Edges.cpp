#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>


int main(){
    int e;
    cin>>e;
    priority_queue<pi, vector<pi>,greater<pi>> pq;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        pq.push({a,b});
    }
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}