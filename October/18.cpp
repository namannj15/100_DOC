//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        queue<Node*> even;
        queue<Node*> odd;
        
        Node *ptr=head;
        while(ptr)
        {
            if(ptr->data%2==1)
            odd.push(ptr);
            else
            even.push(ptr);
            ptr=ptr->next;
        }
        
        if(even.size()==0 || odd.size()==0)
        return head;
        
        head=even.front();
        even.pop();
        head->next=NULL;
        ptr=head;
        
        while(!even.empty())
        {
            Node *temp=even.front();
            even.pop();
            ptr->next=temp;
            ptr=ptr->next;
        }
        
        while(!odd.empty())
        {
            Node *temp=odd.front();
            odd.pop();
            ptr->next=temp;
            ptr=ptr->next;
        }
        
        ptr->next=NULL;
        return head;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
