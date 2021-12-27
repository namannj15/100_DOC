#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* constructTree(char postfix[])
{
//code here
stack<et *> s;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isalpha(postfix[i]))
        {
            et *node = (struct et *)malloc(sizeof(struct et));
            node->value = postfix[i];
            node->left = 0;
            node->right = 0;
            s.push(node);
        }
        else
        {
            et *node1,*node2,*node3;
            node3 = (struct et *)malloc(sizeof(struct et));
            node3->value = postfix[i];
            node2 = s.top();
            node3->right = node2;
            s.pop();
            node1 = s.top();
            node3->left = node1;
            s.pop();
            s.push(node3);
        }
    }
    return s.top();

}
