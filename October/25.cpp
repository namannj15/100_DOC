#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


 // } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // 	Write your code here
        vector<int> adj[n],in(n),dist(n,INT_MIN);
        vector<bool> vis(n,false),rec(n,false);
        for(auto& edge:dependency){
            adj[edge.first].push_back(edge.second);
            in[edge.second]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!in[i]){
                dist[i] = duration[i];
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            cnt++;
            
            for(auto& u:adj[v]){
                in[u]--;
                dist[u] = max(dist[u],dist[v]);
                if(!in[u]){
                    dist[u] += duration[u];
                    q.push(u);
                }
            }
        }
        
        return (cnt==n)?*max_element(dist.begin(),dist.end()):-1;
        
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends