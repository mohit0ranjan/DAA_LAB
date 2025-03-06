#include <iostream>
using namespace std;

class Node {
    public:
    int key;
    Node* left;
    Node* right;
    int height;

};


int getheight(Node*n){
    if(n==NULL) return 0;
    return n->height;
}


int getBalance(Node*n){
    if (n==NULL) return 0;
    return getheight(n->left)-getheight(n->right);;

}

Node* createNode(int key){
    Node*node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node*y){
    Node*x = y->left;
    Node*T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getheight(y->left),getheight(y->right))+1;
    x->height = max(getheight(x->left),getheight(x->right))+1;
    return x;
}

Node* leftRotate(Node*x){
    Node*y = x->right;
    Node*T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getheight(x->left),getheight(x->right))+1;
    y->height = max(getheight(y->left),getheight(y->right))+1;
    return y;
}

Node* insert(Node*node,int key){
    if(node==NULL) return createNode(key);

    if(key<node->key) node->left = insert(node->left,key);

    else if(key>node->key) node->right = insert(node->right,key);
    else return node;

    node->height = 1+max(getheight(node->left),getheight(node->right));
    int balance = getBalance(node);


    if(balance>1 && key<node->left->key) return rightRotate(node);
    if(balance<-1 && key>node->right->key) return leftRotate(node);
    if(balance>1 && key>node->left->key){

        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && key<node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}



void inorder(Node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}




int main (){
    Node*root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);

    cout<<"Insertion in AVL TREE \n";
    inorder(root);
    return 0;
}