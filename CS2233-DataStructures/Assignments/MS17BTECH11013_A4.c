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

struct listNode *front = NULL;
struct listNode *rear = NULL;

struct Graph
{
    struct listNode *adjList;

};


struct node *getNewNode(int val)
{
    struct listNode *newNode = (struct node *)malloc(sizeof(struct listNode));
    newNode->v = val;
    newNode->next = NULL;

    return newNode;
};

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

int getFront()
{
    if(front != NULL)
    {
        return front->v;
    }
}

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


/*
// function to free list after each line
void FreeList(struct list* head){
	struct list* temp;
	while(head!=NULL){
		temp = head;
		head = head->next;
		free(temp);
	}head = NULL;
}

void free_graph(int n, struct list **graph){
	int i=0;
	for(i=0; i<n; i++) FreeList(graph[i]);
	return;
}
*/


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
        int visited[s];

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

	 if(startVertex != endVertex)
     {

        //myGraph[startVertex]->adjList = insertEdge(myGraph[startVertex]->adjList, endVertex);
        // myGraph[endVertex]->adjList = insertEdge(myGraph[endVertex]->adjList, startVertex);

       // printf(" ( %d , %d ) edge and ( %d , %d ) edge  added\n", startVertex, endVertex,endVertex,startVertex);
        adjList[startVertex] = insertEdge(adjList[startVertex], endVertex);
        adjList[endVertex] = insertEdge(adjList[endVertex], startVertex);


     }

	 if(delimiter == '\n') break; // Detecting end of line.
       }
     }
     else if(choice == 'B'){
       scanf("%d",&startVertex);
       // Call BFS on your graph starting from startVertex here.
        // bfs(adjList, startVertex ,numberOfVertices);


        for(int i = 0; i < numberOfVertices; i++)
        {
            myGraph[i] = adjList[i];
        }

        // bfs(myGraph, startVertex, numberOfVertices);
        bfs(myGraph,  startVertex, numberOfVertices);
        printf("\n");
     }
   }
   return(0);
}
