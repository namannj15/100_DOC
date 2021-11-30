// Initial Template for C++

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
// User function Template for C++

class Solution{
    
    public:
    pair<int, int> shortestRange(Node *root) {
        // Your code goes here
        unordered_map<int, vector<int>> nums;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        nums[x.second].push_back(x.first->data);
        if (x.first->left)q.push({x.first->left, x.second + 1});
        if (x.first->right)q.push({x.first->right, x.second + 1});
    }
    int k = nums.size(), ans = 1e9;
    pair<int, int> range = { -1e9, 1e9};
    vector<int> ptr(k, 1);
    multiset<array<int, 2>> s;
    for (int i = 0; i < k; i++)s.insert({nums[i][0], i});
    while (1) {
        auto x = *s.begin(), y = *s.rbegin();
        if (ans > y[0] - x[0])ans = y[0] - x[0], range = {x[0], y[0]};
        else if (ans == y[0] - x[0])range = min(range, {x[0], y[0]});
        if (ptr[x[1]] == nums[x[1]].size())break;
        s.erase(s.find(x));
        s.insert({nums[x[1]][ptr[x[1]]], x[1]});
        ptr[x[1]]++;
    }
    return {range.first, range.second};
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}  // } Driver Code Ends
