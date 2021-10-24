#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int height(Node* temp)
    {
        if(!temp)
          return 0;
        return max(height(temp->left),height(temp->right))+1;
    }  
    bool isHeap(Node* root,int h)
    {
        deque<Node*> deque;
        deque.push_back(root);
        int level = 0;
        while(!deque.empty())
        {
            int size = deque.size();
            level++;
            for(int i=0; i<size; i++)
            {
                Node* temp = deque.front();
                deque.pop_front();
                if(temp->left and temp->right)
                {
                  if( (temp->left->data > temp->data) or (temp->right->data) > temp->data )
                      return false;
                    deque.push_back(temp->left);
                    deque.push_back(temp->right);
                }
                else if(!temp->left and temp->right)
                  return false;
                else if(temp->left and !temp->right)
                  {
                      if(level != h-1 or temp->left->data > temp->data)
                       return false;
                      deque.push_back(temp->left);
                  }
                else 
                  {
                      if(level !=h)
                       return false;
                      
                  }
            }
        }
      return true;
    }
    bool isHeap(struct Node* tree) {
        // code here
              int h = height(tree);
       return isHeap(tree,h);
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}  // } Driver Code Ends