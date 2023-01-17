#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* Merge(Node* left, Node* right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    
    while(left!=NULL)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }
    while(right!=NULL)
    {
        temp->child = right;
        temp  = right;
        right = right->child;
    }
    ans = ans->child;
    return ans;
}
Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next== NULL)
    {
        return head;
    }
    else
    {
        Node* down = head;
        Node* right = head->next;
        down->next = NULL;
        right = flattenLinkedList(right);
        Node* ans = Merge(down,right);
        return ans;   
    }
}

