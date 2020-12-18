/*
Assignment 4
Roll Number: MS17BTECH11013
Name: PADIGAM PAVAN KALYAN

*/

#include<stdio.h>
#include<string.h>

struct listNode {

	int v;
	struct listNode *next;

};

// front and rear pointers to point a queue
struct listNode *front = NULL;
struct listNode *rear = NULL;

//  list to hold the neighbours of a given vertex
// make a array of this list for all vertices that will give the adj list
struct Graph
{
    struct listNode *adjList;

};

// allocates a new node with the value val and next pointer to be null
struct node *getNewNode(int val)
{
    struct listNode *newNode = (struct node *)malloc(sizeof(struct listNode));
    newNode->v = val;
    newNode->next = NULL;

    return newNode;
};


// insert into the queue
void enQueue(int k)
{
    struct listNode* temp = getNewNode(k);

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

}

// get the front element of the  queue
int getFront()
{
    if(front != NULL)
    {
        return front->v;
    }
}


// remove the last element of the queue
void deQueue()
{
    if( front == NULL)
    {
        return ;
    }

    struct listNode *temp = front;

     front = front->next;

    if( front == NULL)
    {
        rear = NULL;
    }

    free(temp);

}

// inserts the edge to the list in a sorted manner
struct listNode* insertEdge(struct listNode* head, int value)
{
    struct listNode *newNode;
    newNode = getNewNode(value);


    struct listNode *current;

    // if the value is greater than head node add it to the left of head
    if(head == NULL || head->v >= newNode->v )
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        current = head;

        while(current->next != NULL && current->next->v < newNode->v)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// utility function to print the adj list
void printGraph(struct listNode *head)
{
    struct listNode *temp = head;

    while(temp != NULL)
    {
        printf(" v = %d", temp->v);
        temp = temp->next;
    }
    printf("\n");
}


void bfs(struct Graph* adjlist[], int src, int s)
{
    // to make a note whether a given node is visited or not whose value can be 0 or 1
    // 0 means not visited; 1 means visited

        int visited[s];

    // iniitally all nodes are not visited
        for(int i =0; i < s; i++)
        {
            visited[i] = 0;
        }

        enQueue(src);
        visited[src] = 1;

        while( !(front == NULL && rear == NULL) )
        {
            int node = getFront();
            deQueue();

            printf("%d ", node);


            struct listNode* temp = adjlist[node];

            while(temp != NULL)
            {
                if(visited[temp->v] == 0)
                {
                    enQueue(temp->v);
                    visited[temp->v] = 1;
                }
                temp = temp->next;
            }

        }
    }

int main(){
  char choice;
  int numberOfVertices, startVertex, endVertex;

  // Fetching number of vertices
  scanf("%d",&numberOfVertices);

  // Create your adjacency list's array of head vertices here.

    struct Graph *myGraph[numberOfVertices];

    // struct graph *myGraph = NULL;
    struct listNode *adjList[numberOfVertices];

    for(int i = 0; i < numberOfVertices; i++)
    {
        myGraph[i] = NULL;
        adjList[i] = NULL;
    }


  while(scanf(" %c",&choice)!=-1){
     if(choice == 'N'){
       char delimiter;
       scanf("%d", &startVertex);

       while(scanf("%d%c", &endVertex, &delimiter)){

	 // Add the edge (startVertex, endVertex) to your graph here.

        adjList[startVertex] = insertEdge(adjList[startVertex], endVertex);
        adjList[endVertex] = insertEdge(adjList[endVertex], startVertex);

	 if(delimiter == '\n') break; // Detecting end of line.
       }
     }
     else if(choice == 'B'){
       scanf("%d",&startVertex);

        for(int i = 0; i < numberOfVertices; i++)
        {
            myGraph[i] = adjList[i];
        }
       // Call BFS on your graph starting from startVertex here.
        bfs(myGraph,  startVertex, numberOfVertices);

        printf("\n");
     }
   }
   return(0);
}
