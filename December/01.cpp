#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n = grid.size();
    int m = grid[0].size();
    int timer = -1;
    queue<pair<int, int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
                grid[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto p = q.front();
            q.pop();
            int sr = p.first;
            int sc = p.second;

            for(int d=0; d<4; d++){
                int r = sr + dir[d][0];
                int c = sc + dir[d][1];
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                    grid[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        timer++;
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j]==1)
                return -1;
    return timer;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
