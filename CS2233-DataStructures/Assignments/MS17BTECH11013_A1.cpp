#include<iostream>
#include<sstream>
#include<iterator>
#include<string>

using namespace std;

// strcmp function from the previous assignment 0
bool strcmp(string numberPlate1,string numberPlate2 )
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
      while(i < len)
      {
        if( (numberPlate1.at(i) < numberPlate2.at(i)) || (numberPlate1.at(i) < numberPlate2.at(i) ) )
        {
            // cout << 1 << endl;
            return true;
            break;
        }
        else if( (numberPlate1.at(i) > numberPlate2.at(i)) || (numberPlate1.at(i) > numberPlate2.at(i) ))
        {
            // cout << 0 << endl;
            return false;
            break;
        }

        i++;
      }

}

// Structure which represents a node in BST
struct Node
{
    // which hold the numberPlate("string") in the node
    string data;

    // pointer to the left node of the same type struct node
    Node *left;

    // pointer to the right node of the same type struct node
    Node *right;
};



// Function to create a new node with the value data and return that address
Node* GetNewNode(string data)
{
    // create a new node by using new keyword which allocates memory of size struct node
    Node *newNode = new Node();
     // (*newNode).data = data;

     // put the data to the data of the node
    newNode->data = data;

    // As it is a new node initially point the left and right pointer to null
    newNode->left = newNode->right = NULL;

    return newNode;
}

void printPath(Node *root, string val)
{

    // If left node has reached or empty BST is given then return from the function
    if( root == NULL)
        return ;

    // If we have reached to the given node where the data part is equal then simply return
    // we use compare member function of string class
    else if( (val.compare(root->data) == 0) )
    {
        return;
    }
    // If val is less than root->data then recursively go the left sub tree by calling printpath and before going print L which
    // indicates the path taken
    else  if (strcmp(val,root->data) ) // val < root->data
    {
        cout << "L";
        printPath(root->left, val);
        return;
    }
    else
    {
        // if val is not less than root->data then recursively go the right sub tree by calling printpath and before going print R which indicates
        // right path is taken
        cout << "R";
        printPath(root->right, val);
        return;
    }
}

// function which return true if the given val exists in the BST if not then return false
bool Search(Node *root, string data)
{
    // If empty BST or leaf node is reached then return false
    if(root == NULL)
    {
        return false;
    }
    // If the given node is reached then given val exist and return true
    else if( ((root->data).compare(data) ) == 0 )  //  root->data == data)
        return true;
    // Given data is less than root->data then search in the left BST by recursively calling the Search with root->left argument
    else if( strcmp(data, root->data) )  // data <= root->data )
        return Search(root->left,data);
    // if given data is more than root->data then search in the right BST by recursively calling the Search with root->right as argument
    else return Search(root->right, data);
}


// Function which performs insert operation on the BST here we pass the address/ pointer to root node and val/data to be inserted

Node* Insert(Node* root, string data)
{
    // if BST is empty or correct position/leaf node is reached then insert the node to the root of given BST
    if(root == NULL)
    {
        root = GetNewNode(data);
        return root;
    } else if (  strcmp(data,root->data) )   //root->data > data)
    {
        // if data is less than root->data that means data has to be inserted in the left of the BST
        // Insert by recursively calling the Insert function which finally returns the correct pointer to the node
        root->left = Insert(root->left, data);

    } else
    {
        // if data is greater than root->data that means data has to be inserted in the right of the BST
        // Insert by recursively calling the Insert function which finally returns the correct pointer to the node
        root->right = Insert(root->right, data);
    }

    return root;
}


int main(){
  string firstLine;
  string numberPlate;
  char choice;

  Node* root = NULL; // root is actually a pointer to root

  //Fetching only the first line of input.
  getline(cin,firstLine);
  stringstream stringSplitter(firstLine);

  // Parsing the string word by word.
  while(stringSplitter >> numberPlate){
    // Call your BST Insert function here with argument: numberPlate
     root = Insert(root,numberPlate);

  }

  // Main input handler to serve requests.
  while(cin >> choice >> numberPlate){
    if(choice=='S'){
      // Call your BST Search function here with argument: numberPlate
      if(Search(root,numberPlate) )
      {
          // If the given numberPlate exists in the BST then cout "1 " and print the path
          cout << "1 ";
           printPath(root, numberPlate);
           cout << endl;
      }
      else
      {
          // if the given numberPlate dosen't exists in the BST then cout "0 "
          cout << "0" << endl;
      }
    }

  }

  return(0);
}

// MS17BTECH11013
// Pavan Kalyan
