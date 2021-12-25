#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
pair<node*, node*> quicksort(node* head, node* tail) {
    if(head == NULL) return {NULL, NULL};
    if(head == tail) return {head, tail};

    node* dummy1 = new node(-1);
    node* dummy2 = new node(-1);
    node *head1 = dummy1, *head2 = dummy2;
    node* temp = head;

    while(temp != tail) {
        if(temp -> data <= tail -> data) {
            dummy1 -> next = temp;
            dummy1 = dummy1 -> next;
        } else {
            dummy2 -> next = temp;
            dummy2 = dummy2 -> next;
        }
        temp = temp -> next;
    }
    dummy1 -> next = NULL;
    dummy2 -> next = NULL;
    
    pair<node*, node*> p1 = quicksort(head1->next, dummy1);
    pair<node*, node*> p2 = quicksort(head2->next, dummy2);
    
    if(head1 -> next == NULL) {
        temp -> next = p2.first;
        return {temp, p2.second};
    }
    if(head2 -> next == NULL) {
        p1.second -> next = temp;
        return {p1.first, temp};
    }
    
    p1.second -> next = temp;
    temp -> next = p2.first;
    
    return {p1.first, p2.second};
}

void quickSort(struct node **headRef) {
    if(headRef == NULL) return;
    node* head = *headRef;
    node* tail = *headRef;
    while(tail -> next != NULL)
        tail = tail->next;
    *headRef = quicksort(head, tail).first;
}
