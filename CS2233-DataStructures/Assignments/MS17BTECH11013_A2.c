/*
Assignment 2
Roll Number: MS17BTECH11013
Name: Pavan Kalyan Padigam

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// struct to hold data of a BST node
struct bstNode
{
    char data[7];
    struct bstNode *left;
    struct bstNode *right;
    struct bstNode *parent;

};


// prototype for functions
struct bstNode* getMinEle(struct bstNode *node);
struct bstNode* getMaxEle(struct bstNode *node);
struct bstNode* getGreaterAncestor(struct bstNode *node);
struct bstNode *getSmallerAncestor(struct bstNode *node);
struct bstNode* Sucessor(struct bstNode *node);
struct bstNode* Predessor(struct bstNode *node);
struct bstNode* getNewNode(char* value );
struct bstNode* insertBstNode(struct bstNode* node, char* key);
struct bstNode* searchNode(struct bstNode*root, char* value);
void preOrderTraversal(struct bstNode *root );
int strcm(char* numberPlate1,char* numberPlate2 );
void printPath(struct bstNode *root, char* val);
struct bstNode* deleteNode(struct bstNode* root, char *val);
char* printSucessor(struct bstNode *node);
char* printPredessor(struct bstNode *node);
void deleteTree(struct bstNode* node);


int main(){
  char choice, numberPlate[7];
  _Bool requests = 0;

  struct bstNode *root = NULL; // a pointer to root

  struct bstNode *testNode;
  struct bstNode *ansNode;

  // Fetching till we hit the first request
   while(scanf("%s",numberPlate)!=-1){
    if(!requests){
      if(strlen(numberPlate) == 1){ // Detecting start of request lines.
	choice = numberPlate[0];
	requests = 1;
      }
      else{
	// *** Call your insert function here with argument numberPlate ***

            root = insertBstNode(root,numberPlate);
      }
    }
    else break; // choice and numberPlate have values to be processed!!
   }


   do{ // Ugly do-while to process first request line before first scanf.

     testNode = searchNode(root,numberPlate);

     if(choice == 'S'){

       //*** Call your search function here with argument numberPlate ***

      if( testNode != NULL)
      {
          // If the given numberPlate exists in the BST then cout "1 " and print the path
           printf("1 ");
           printPath(root, numberPlate);
           printf("\n");
      }
      else
      {
          printf("0\n");
      }
     }
     else if(choice == '<'){
       //*** Call your predecessor function here with argument numberPlate ***
    if(searchNode(root,numberPlate) != NULL)
    {
        // If the numberPlate does exist in the BST then find the predessor of it
        if(Predessor(searchNode(root, numberPlate)) != NULL)
        {
            // if the predessor exists then print
            printf("%s\n", printPredessor(Predessor(searchNode(root, numberPlate))));

        }
        else
        {
            // if the predessor doesn't exist then print 0
            printf("0\n");
        }
    }
    else
    {
        // If the numberPlate dosen't exists in the tree then add it into the BST and then find the predessor, print and delete the numberPlate node;

        // the numberPlate gets added as a left node as the BST is already constructed
          root = insertBstNode(root,numberPlate);
          struct bstNode* ansNode = Predessor(searchNode(root,numberPlate));
          printf("%s\n", printPredessor(ansNode));

          // delete the node; it's only deleting the leaf node as we already know
          root = deleteNode(root,numberPlate);
    }

     }
     else if(choice == '>'){
       //*** Call your successor function here with argument numberPlate ***

    if(searchNode(root,numberPlate) != NULL)
    {
        // If the numberPlate does exist in the BST then find the Sucessor of it
        if(Sucessor(searchNode(root, numberPlate)) != NULL)
        {
            // if the Sucessor exists then print
            printf("%s\n", printSucessor(Sucessor(searchNode(root, numberPlate))));

        }
        else
        {
            // if the Sucessor doesn't exist then print 0
            printf("0\n");
        }
    }
    else
    {
        // If the numberPlate dosen't exists in the tree then add it into the BST and then find the predessor, print and delete the numberPlate node;

        // the numberPlate gets added as a left node as the BST is already constructed
          root = insertBstNode(root,numberPlate);
          struct bstNode* ansNode = Sucessor(searchNode(root,numberPlate));
          printf("%s\n", printSucessor(ansNode));

          // delete the node; it's only deleting the leaf node as we already know
          root = deleteNode(root,numberPlate);
    }

     }

   }while(scanf("%*[\n]%c %6s",&choice, numberPlate)!=-1);

   // delete the tree
   deleteTree(root);

   return(0);
}

// Utility function to return value of Sucessor
char* printSucessor(struct bstNode *node)
{
    char *emty = "0";

    if(node != NULL)
    {
        return node->data;
    }
    else
        return emty;

}

// Utility function to return value of predessor
char* printPredessor(struct bstNode *node)
{
    char *emty = "0";

    if(node != NULL)
    {
        return node->data;
    }
    else
        return emty;

}

// Delete Tree recursively
void deleteTree(struct bstNode* node)
{

    if( node == NULL )
        return;

    //delete children
    deleteTree(node->left);
    deleteTree(node->right);

    //then delete node
    free(node);
}

// comparision function which return an int which can be 1,0 or 6
int strcm(char* numberPlate1, char* numberPlate2 )
{
     // As we already know the length of the input string is 6
      int len = 6;

      // Looping variable
      int i = 0;

      /************  LOGIC *******************************************************************************************

       loop through all characters using k, if it mets any of the two conditions

      i) character at k of A < character at k of B
          that means A < B. return 1

      we can't do else as there might be chances that both char are equal so,

      ii) character at k of A > character at k of B
           that means A > B. return 0

      ***************************************************************************************************************/

      int count = 0;
      while(i < len)
      {
        if( (numberPlate1[i] < numberPlate2[i] ))
        {
            // cout << 1 << endl;
            return 1;
            break;
        }
        else if( (numberPlate1[i] > numberPlate2[i] )  )
        {
            // cout << 0 << endl;
            return 0;
            break;
        }
        else if((numberPlate1[i] == numberPlate2[i] ) )
        {
            count++;
        }

        i++;
      }

      // if the two strings are equal then return 6
      if(count == 6)
        return 6;

}

struct bstNode* getMinEle(struct bstNode *node)
{

    // used for iteration
    struct bstNode *curr = node;

    // it's finds the min element iteratively by searching in the left subtree of the node until it reaches NULL left node/ leaf node
    while(curr->left != NULL)
        curr = curr->left;

    return curr;
}

struct bstNode* getMaxEle(struct bstNode *node)
{
     // used for iteration
    struct bstNode *curr = node;

    // it finds the max element iteratively by searching in the right subtree of the node until reached NULL right node/leaf node
    while(curr->right != NULL)
        curr = curr->right;

    return curr;
}


struct bstNode *getGreaterAncestor(struct bstNode *node)
{
    // root node is reached
    if(node->parent == NULL)
        return NULL;

    struct bstNode *parent = node->parent;

    // Recursively find the ancestor who is greater than the node
    // if it finds the node then return parent
    if( strcm(node->data ,parent->data )  == 1 )
        return node->parent;
    else
        return getGreaterAncestor(node->parent);
}

struct bstNode *getSmallerAncestor(struct bstNode *node)
{
    // root node is reached
    if(node->parent == NULL)
        return NULL;

    struct bstNode *parent = node->parent;

    // Recursively find the ancestor who is smaller than the node
    // if it finds the node then return parent
    if( strcm(parent->data, node->data)  == 1 )
        return node->parent;
    else  // else calls it's self on parent node
        return getSmallerAncestor(node->parent);
}

struct bstNode* Sucessor(struct bstNode *node)
{
    // if the right child is not there then find  ancestor which is greater then node
    if(node->right == NULL)
    {
        return getGreaterAncestor(node);
    }
    else
    {
        // if the right child exists then find the minimum element in the right sub tree
        return getMinEle(node->right);
    }
}

struct bstNode* Predessor(struct bstNode *node)
{
    // if the left child of node is not there then find ancestor which is smaller than node
    if(node->left == NULL)
    {
        if(node->parent != NULL)
        {
            return getSmallerAncestor(node);
        }
    }
    else
    {
        // if the left child exists then find the maximum element in the left subtree
        return getMaxEle(node->left);
    }
}


struct bstNode *getNewNode(char * value )
{
    // allocates spaces for new node and return pointer to the node
    struct bstNode *newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
    strcpy(newNode->data, value);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

struct bstNode* insertBstNode(struct bstNode* node, char* value)
{
    if(node == NULL)
    {
        return getNewNode(value);
    }
    else if( strcm(value,node->data)  == 1 )
    {
        // insert it in the left subtree if value is less than node->data
        node->left = insertBstNode(node->left, value);
        (node->left)->parent = node;
    }else if( strcm(value,node->data)  == 0 )
    {
        // insert it in the right subtree if value if greater than node->data

        node->right = insertBstNode(node->right, value);
        (node->right)->parent = node;
    }

    return node;
}

struct bstNode* searchNode(struct bstNode* root, char* value)
{
    if(root == NULL)
        return NULL;

    // flag to hold the value of fun which returns either 1,0,6
    int res = strcm(value,root->data );

    if( res  == 1 )
    {
        // if the value is less then root->data then search in the left subtree
        return searchNode(root->left, value);
    }
    else if( res == 0 )
    {
        // if the value is greater then root->data then search in the right subtree
       return searchNode(root->right, value);
    }
    else if(res ==  6)
    {
        // if both are equal then return the root pointer
       return root;
    }

}

// prints the pre Order traversal of node

void preOrderTraversal(struct bstNode *node )
{
    if(node == NULL)
        return;

    printf("%s\t", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);

    return;
}


// Delete node

struct bstNode* deleteNode(struct bstNode* root, char *val)
{
    struct bstNode *temp;

    // Empty Tree
    if(root == NULL)
    {
        return root;
    }
    if(strcm(val,root->data) == 1)     // if val is less than root-> data
    {
        root->left = deleteNode(root->left, val);       // delete val which is present in the left subtree recursively to find
    }
    else if(strcm(val,root->data) == 0)
    {
        root->right = deleteNode(root->right, val);        // delete val which is present in the right sub tree recursively to find
    }
    else
    {
        // base cases

        // if root node has only one child

        if(root->left == NULL)          // if root has no left child then delete the node and return the right child which gets attached to the right subtree of parent
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)   // if root has no right child then delete the node and return the left child which gets attached to the left subtree of parent
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // if root node has 2 children then replace the node by it's sucessor

        temp = Sucessor(root);

        // copy the value of sucessor into root data
        strcpy( root->data, temp->data);

        // now delete the sucessor which is present in the right sub tree, as we know node contains two children
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void printPath(struct bstNode *root, char* val)
{

    // If left node has reached or empty BST is given then return from the function
    if( root == NULL)
    {
         return ;
    }
    else  if (strcm(val,root->data) == 1) // val < root->data
    {
        // If val is less than root->data then recursively go the left sub tree by calling printpath and before going print L which
        // indicates the path taken

        printf("L");
        printPath(root->left, val);
        return;
    }
    else if (strcm(val,root->data) == 0)
    {
        // if val is not less than root->data then recursively go the right sub tree by calling printpath and before going print R which indicates
        // right path is taken
        printf("R");
        printPath(root->right, val);
        return;
    }
    else
    {
            // If we have reached to the given node where the data part is equal then simply return
            // we use compare member function of string class
        return;
    }
}

/*
int main()
{

    struct bstNode *root = NULL;

    int n;
    printf("Enter number of values to be added" );
    scanf("%d", &n);


    while(n--)
    {
        char numPlate[7] ;
        scanf("%6s",numPlate);
        root = insertBstNode(root,numPlate);
    }


    printf("Enter the value to find the sucessor \n");
    char s[7];


       scanf("%6s",s);

    if(searchNode(root,s) != NULL)
    {
        if(Sucessor(searchNode(root, s)) != NULL)
        {
            printf("%s\n", printSucessor(Sucessor(searchNode(root, s))));

        }
        else
        {
            printf("0\n");
        }
    }
    else
    {
          root = insertBstNode(root,s);
          struct bstNode* ansNode = Sucessor(searchNode(root,s));
          printf("%s\n", printSucessor(ansNode));
          root = deleteNode(root,s);
    }

    return 0;
}

*/

