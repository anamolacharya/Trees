
// AUTHOR: Anamol Acharya
// FILENAME: Lab6.c
// SPECIFICATION: Create a BST including insertion, deletion, preorder traversal and displaying the tree
// FOR: CS 2413 Data Structure Section 002



#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>

struct node                                             // Create a struct for each node in the tree
{
    int data;                                           // declare the value data for the node
    struct node *left;                                  //struct the pointer in left direction
    struct node *right;                                 //struct the pointer in right direction
};


struct node* node(int data)                                             
{ 
     struct node* node = (struct node*)malloc(sizeof(struct node));//allocate the memory for the new node 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 

                                                        //calling the function
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
struct node *deleteElement(struct node *, int);
int height(struct node *tree);
void printGivenLevel(struct node* tree, int level);
void Display(struct node *tree);
   

 
 bool search(struct node * tree, int val)               //creating a search function
 {
     
    if(tree==NULL)                                      //check if the tree is null or not
return false;                                           //return if tree false
    
    if(tree->data== val)                                //check if the data of the tree is val
    return true;
    
    bool res1 = search(tree->left, val);
    bool res2 = search(tree->right, val);
    return res1 || res2;
     
 }
     
int main()
{
    int option, val;                                    //declare an option and val interger variable
    struct node *ptr;                                   //struct a pointer to node
    create_tree(tree);
    do
    {                                                   //The main menu dispaly
        printf("\n        **Welcome to BST** \n");
        printf("\n 1. Insert a number in the tree");
        printf("\n 2. Preorder Traversal of the tree");
        printf("\n 3. Delete a number in the tree");
        printf("\n 4. Search a number in the tree");
        printf("\n 5. Dislay the structure of the tree");
        printf("\n 6. Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);                           //reads the input
        switch(option)                                  //create a switch case 
        {
            case 1:                                     //switch case for inserting the element
            printf("\n Enter the value of the new node : ");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
            
            case 2:                                     //switch case for preorder traversal of the tree
            printf("\n The elements of the tree are : \n");
            preorderTraversal(tree);
            break;

            case 3:                                     //switch case for deleting the element 
            printf("\n Enter the element to be deleted : ");
            scanf("%d", &val);
            tree = deleteElement(tree, val);
            break;

            case 4:                                     //switch case for searching the element 
            printf("\n Enter a node element to be searched: ");
            scanf("%d", &val);
            if (search(tree, val ))                     //check if the element is in the tree or not
                printf("Yes,The element is in the tree! \n",val);
                else
                    printf("No,The element is not in the tree! \n");
                    break;
                    
            case 5:                                     //switch case for dispalying the tree
            printf("\n Display the tree: \n");
            Display(tree);
            break;

        }
    }while(option!=6);
    getch();        
    return 0;
}

void create_tree(struct node *tree)                     //Create a funtion to create the tree 
    {
        tree = NULL;
    }
    
struct node *insertElement(struct node *tree, int val)  //create a funtion to insert a element in the tree
    {
        struct node *ptr, *nodeptr, *parentptr;         //struct the pointer needed for inserting the element 
        ptr = (struct node*)malloc(sizeof(struct node)); // allocate the memory of the node
        ptr->data = val;
        ptr->left = NULL;
        ptr->right = NULL;
        if(tree==NULL)                                  // check the tree is null or not 
        {
            tree=ptr;
            tree->left=NULL;
            tree->right=NULL;
        }
        else
        {
            parentptr=NULL;
            nodeptr=tree;
            while(nodeptr!=NULL)                        
            {
                parentptr=nodeptr;
                if(val<nodeptr->data)                   //compare val with data to direct the node to its direction
                nodeptr=nodeptr->left;
                else
                nodeptr = nodeptr->right;
            }
                if(val<parentptr->data)                 //check if val is less than data, then direct ptr left 
                parentptr->left = ptr;
                else
                parentptr->right = ptr;                 //else right
        }
        return tree;
    }
    
void preorderTraversal(struct node *tree)               //create a preorder traversal funtion
    {
        if(tree == NULL)
    return;
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);

}

struct node *deleteElement(struct node *tree, int val)
    {
        struct node *cur, *parent, *suc, *psuc, *ptr;
        if(tree->left==NULL)
    {
        printf("\n The tree is empty ");
        return(tree);
    }
        parent = tree;
        cur = tree->left;
        while(cur!=NULL && val!= cur->data)
    {
        parent = cur;
        cur = (val<cur->data)? cur->left:cur->right;
    }
    if(cur == NULL)
    {
        printf("\n The value to be deleted is not present in the tree");
        return(tree);
    }
        if(cur->left == NULL)
        ptr = cur->right;
        else if(cur->right == NULL)
            ptr = cur->left;
        else
    {
                                                                
        psuc = cur;                                             // to find in–order successor and its parent
        cur = cur->left;
        while(suc->left!=NULL)
    {
        psuc = suc;
        suc = suc->left;
    }
        if(cur==psuc)
    {

        suc->left = cur->right;
    }
        else
        {
            
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc;
    }

    if(parent->left == cur)
    parent->left=ptr;
    else
    parent->right=ptr;
    free(cur);
    return tree;
    }


int height(struct node *tree)                           //create a height funtion
{
    int leftheight;                                     //declare leftheight and right height integer variable
    int rightheight;
    if(tree==NULL)                                      // check if tree is null or not
    return 0;
    else
    {
        leftheight = height(tree->left);
        rightheight = height(tree->right);
        if(leftheight > rightheight)
        return (leftheight + 1);
        else
        return (rightheight + 1);
    }
}

void printGivenLevel(struct node* tree, int level)      //create afunction to find the level of tree
{
    if (tree == NULL)
        return;
    if (level == 1)
        printf("%d ", tree->data);
    else if (level > 1)
    {
        printGivenLevel(tree->left, level-1);
        printGivenLevel(tree->right, level-1);
    }
}

void Display(struct node *tree)                         //create a function to display the tree using the height of the tree
{
    int h = height(tree);
    for (int i= 1; i <= h ; i++ )
    {
       printGivenLevel(tree, i);
       printf("\n");
    }
   
}