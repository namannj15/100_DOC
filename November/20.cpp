#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    unordered_map<Node*,Node*>um; // to store the parent of each node

    // it returns the refence to target node
    Node* storeparent(Node*root,int target)
    {
        Node*t; //for target node
        if (root==NULL)
          return t;

        um[root]=NULL; // parent of root is null

        //standard BFS implementation

        queue<Node*>q;

        q.push(root);

        while(!q.empty())
        {

          Node*p=q.front();

          if (p->data==target)
          {
              t=p;// here we have found our target node
          }

        if (p->right)// if right child exist
        {
            um[p->right]=p;// set parent of right chlid of p as p
            q.push(p->right);

        }
        if (p->left)
        {
            um[p->left]=p;// set parent of left chlid of p as p
            q.push(p->left);
        }

        q.pop();

        }
        return t;// return this target node
    }

    int sum_at_distK(Node* root, int target, int k)
    {
        // Your code goes here
         //store parent of each node and get reference to target node
         Node*t=storeparent(root,target);

         if (t==NULL) // if target node is not present
           return 0;

         long long int sum=0; // sum of all the nodes upto level=k

         //BFS implementation

         queue<Node*>q;

         set<Node*>s;

         q.push(t);
         s.insert(t);
         //sum+=t->data;
         int level=0;

         while(!q.empty() and level<=k)
         {
             int size=q.size();

             for (int i=0;i<size;i++)
             {Node*f=q.front();
             sum+=f->data;

             if (f->right && s.find(f->right)==s.end() )
             {
                 q.push(f->right);
                 s.insert(f->right);
             }

             if (f->left && s.find(f->left)==s.end())
             {
                 q.push(f->left);
                  s.insert(f->left);

             }
             if (um[f] && s.find(um[f])==s.end())// for parent of f
             {
                 q.push(um[f]);
                  s.insert(um[f]);
                 //sum+=um[f]->data;
             }
             q.pop();
             }
             level++;// now we will move to next level
         }



         return sum;// sum of all the nodes till level k

    }


};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends
