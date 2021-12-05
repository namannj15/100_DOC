#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{ 
     struct TrieNode
    {
        TrieNode *child[2];
        bool isEnd;
        
        TrieNode()
        {
            for(int i = 0; i < 2; i++)
            {
                child[i] = NULL;
            }
            
            isEnd = false;
        }
    };
    
    void insertRows(TrieNode *root, vector<int> &res, vector<vector<int>> &matrix, int M, int N)
    {
        for(int i = 0; i < M; i++)
        {
            TrieNode *curr = root;
            
            for(int j = 0; j < N; j++)
            {
                int index = matrix[i][j];
                
                if(curr->child[index] == NULL)
                {
                    curr->child[index] = new TrieNode();
                }
                
                curr = curr->child[index];
            }
            
            if(curr->isEnd == true)
            {
                res.push_back(i);
            }
            
            curr->isEnd = true;
        }
    }
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{ 
    // Your code here
  TrieNode *root = new TrieNode();
        vector<int> res;
        
        insertRows(root, res, matrix, M, N);
    
        return res;
} 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


  // } Driver Code Ends
