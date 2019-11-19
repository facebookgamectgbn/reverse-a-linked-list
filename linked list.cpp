#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* rev_root=NULL;

node* append(node* parent, int new_data)
{

    if(parent==NULL)
    {
        node* new_node = new node();
        new_node->data = new_data;
        new_node->next = NULL;
        return new_node;
    }
    parent->next=append(parent->next,new_data);
    return parent;
}

void print_list(node* parent)
{
    if(parent==NULL)
        return;
    cout<<parent->data<<" ";
    print_list(parent->next);
}

void make_list_reverse(node* parent)
{
    if(parent==NULL)
        return;
    make_list_reverse(parent->next);
    rev_root=append(rev_root,parent->data);
}
int main()
{
    node* root=NULL;
    root=append(root,10);
    append(root,20);
    append(root,40);
    append(root,80);
    append(root,160);
    print_list(root);
    cout<<endl;
    make_list_reverse(root);
    print_list(rev_root);
}
