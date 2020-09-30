#include<iostream>
#include<list>
using namespace std;

struct BNode 
{
    int data;
    struct BNode *left;
    struct BNode *right;
};

void bst_insert(int value,struct BNode **root)
{
    BNode *newnode = new BNode;
    newnode->data = value;
    newnode->left=NULL;
    newnode->right=NULL;
    
    if(*root == NULL)
    {
        *root = newnode;
    }
    else
    {
        struct BNode *node = *root;
        while(1)
        {
            if(node->data > value)
            {
                if(node->left == NULL)
                {
                        node->left=newnode;
                         return;
                }
            
                node = node->left;
            }
            else
            {
                if(node->right == NULL)
                {
                     node->right = newnode;
                    return;
                }
                node = node->right;
             }
        }
    }
    return;
}


void inorder_traversal(struct BNode *node)
{
    if(node == NULL)
    {
        return;
    }
    inorder_traversal(node->left);
    cout<<node->data<<" ";
    inorder_traversal(node->right);
}

void preorder_traversal(struct BNode *node)
{
    if(node == NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void postorder_traversal(struct BNode *node)
{
    if(node == NULL)
    {
        return;
    }
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout<<node->data<<" ";
}

void levelorder_traversal(struct BNode *node)
{
    list<BNode*> queue;
    queue.push_back(node);
    
    BNode *current = node;
    
    while(queue.size())
    {
        
        current=queue.front();
        queue.pop_front();
        
        cout<<current->data<<" ";
        
        if(current->left)
            queue.push_back(current->left);
        if(current->right)
            queue.push_back(current->right);
    }
}

BNode *minimun_value_node(BNode *node)
{
    BNode *current = node;
    while(current != NULL && current->left !=NULL)
    {
        current = current->left;
    }
    return current;
}

void delete_node( BNode *&node,int value)
{
    
    if(node == NULL)
    {
        return;
    }
    
    if(value < node->data)
    {
        delete_node(node->left,value);
    }
    else if(value > node->data)
    {
        delete_node(node->right,value);
    }
    else
    {
        
        if(node->left == NULL && node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        
        else if(node->left && node->right)
        {
            BNode *successor = minimun_value_node(node->right);
            node->data = successor->data;
            
            delete_node(node->right,successor->data);
        }
        
        else
        {
            BNode *child = (node->left) ? node->left : node->right;
            BNode *current = node;
            node = child;
            delete current;
            
        }
    }
}


void search_an_element(struct BNode *node, int search)
{
    
    if(node == NULL)
    {
        cout << "element is not present\n";
        return;
    }
    else if( node ->data == search)
    {
        cout<< "element is present\n";
        return;
    }
    else if(search < node->data)
    {
        search_an_element(node->left, search);
    }
    else
    {
        search_an_element(node->right, search);
    }
    return;
}

int main()
{
    struct BNode *root = NULL;
    int size;
    cin>>size;
    int element;
    for(int i=0;i<size;i++)
    {
        cin>>element;
        
        // inserting an element to tree;
        
        bst_insert(element,&root);
    }
    
    // Traversal in Binary search tree
    
    cout<<"Before : deletion\nInorder Traversal\n";
    inorder_traversal(root);
    cout<<endl;
    
    cout<<"Preorder Traversal\n";
    preorder_traversal(root);
    cout<<endl;
    
    cout<<"Postorder Traversal\n";
    postorder_traversal(root);
    cout<<endl;
    
    // Level order Traversal(BSF)
    
    cout<<"Level Order Traversal\n";
    levelorder_traversal(root);
    cout<<endl;
    
    //////////////////////////////////////
    
    // Deleting an element from tree
    
    int delete_element;
    cin>>delete_element;
    
    delete_node(root,delete_element);
    
    cout<<"After deletion\nInorder Traversal\n";
    inorder_traversal(root);
    cout<<endl;
    
    ////////////////////////////////////
    
    //searching in Binary search tree
    
    int search;
    cin>>search;
    search_an_element(root,search);
    
    
    return 0;
}