#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
//PreOrder Traversal
void preOrder(struct node* root){
     if(root!=NULL){
        printf("%d \t",root->data);
        preOrder(root->left);
        preOrder(root->right);

     }
}
//PostOrder Traversal 
void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d \t",root->data);
    }
}
//InOrder Traversal
void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d \t",root->data);
        inOrder(root->right);
    }
} 
//Checking if a Binary TREE is a BST
int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root!=NULL){
       if(!isBST(root->left)){
        return 0;
       }
       if(prev!=NULL && root->data <= prev->data){
        return 0;
       }
       prev=root;
       return isBST(root->right);
    } else {
        return 1;
    }
}
//Searching in BST recursively
struct node* Search(struct node *root, int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    else if(root->data >key) return Search(root->left, key);
     else return Search(root->right, key);

}
// Searching in BST iteratively
struct node* SearchIter(struct node *root, int key){
    while(root!=NULL){
    if(key==root->data) return root;
    else if (key<root->data){
        root=root->left;
    } else root= root->right;
    }
    return NULL;
}
//Insertion in BST
void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* new = createnode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }
}
//Creating inOrder Predecessor 
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
//Deletion in BST
struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

                    //searching for the node to be deleted
    if (value < root->data){
        deleteNode(root->left,value);
    }
    else if (value > root->data){
        deleteNode(root->right,value);
    }
                    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
    }
}


int main(){
    struct node* p= createnode(5);
    struct node* p1= createnode(3);
    struct node* p2= createnode(6);
    struct node* p3= createnode(1);
    struct node* p4= createnode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

   // preOrder(p);
    //printf("\n");
    //postOrder(p);
 
   // inOrder(p);
  //printf("\n");
  
  //printf("%d", isBST(p));

  /* searching 
  struct node* n=Search(p, 6);
  if(n!=NULL){
    printf("found : %d", n->data);
  } else printf("element not found");
  
 struct node* n=SearchIter(p, 9);
  if(n!=NULL){
    printf("found : %d", n->data);
  } else printf("element not found");
  */
 /* insertion in bst
 insert(p,9);
 printf("%d",p->right->right->data);
 */
     inOrder(p);
    printf("\n");
    deleteNode(p, 6);
    inOrder(p);

    return 0;

}