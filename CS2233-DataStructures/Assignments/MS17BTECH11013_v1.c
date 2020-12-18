/*
Assignment 5
Roll Number: MS17BTECH11013
Name: PADIGAM PAVAN KALYAN

*/

#include<stdio.h>
#include<string.h>

struct listNode
{
	int v;
	int weight;
	struct listNode *next;

};

//  list to hold the neighbours of a given vertex
// make a array of this list for all vertices that will give the adj list
struct Graph
{
    struct listNode *adjList;

};

struct minHeapPQue
{
    int vertex;
    int distance;

};

struct pathNode
{
    int d;
    int parent; // shortest adjacency vertex which i assumed to be a parent

};

void swap(struct minHeapPQue *h1, struct minHeapPQue *h2)
{
    struct minHeapPQue temp;

    temp = *h1;
    *h1 = *h2;
    *h2 = temp;

}

void minHeapify(struct minHeapPQue *heap, int n, int i)
{
    int s;
    int leftChild = (2*i)+1;
	int rightChild = (2*i)+2;

	int min = i;

	if((leftChild < n) && (heap[leftChild].distance < heap[min].distance) )
    {
        min = leftChild;
    }

	if((rightChild < n) && (heap[rightChild].distance < heap[min].distance) )
    {
        min = rightChild;
    }

    if(min != i)
    {
        swap(&heap[i], &heap[min] );
        minHeapify(heap,n,i);
    }
}


struct minHeapPQue extractMin(struct minHeapPQue *heap, int n)
{
	struct minHeapPQue min;

	// extract the top/first element of the heap array which gives the min element
	min.distance = heap[0].distance;
	min.vertex = heap[0].vertex;

	// replace the top/element with the last vertex/element
	heap[0].distance = heap[n-1].distance;
	heap[0].vertex = heap[n-1].vertex;

	// decrease the size of the heap array
	n--;

	// call heapify on the top element to find the correct position of the element
	minHeapify(n,heap,0);


	return min;
}


void decreaseKey(struct minHeapPQue *heap, int n, int i, int val)
{
    heap[i].distance = val;

    while(i && heap[i].distance < heap[(i-1)/2].distance )
    {
        swap(&heap[i], &heap[(i-1)/2] );
    }

}


struct path *Dijkstra(struct Graph *g, int n, int source )
{
    // array of pathnode to store the path of shortest distance
    struct pathNode *pthArray = (struct pathNode *)malloc(n *sizeof(struct pathNode));

    struct minHeapPQue *qArray = (struct minHeapPQue *)malloc(n *sizeof(struct minHeapPQue));

    struct minHeapPQue node;

    struct listNode *temp;

    int i;
    for( i = 0; i < n; i++)
    {
        qArray[i].vertex = i;

        // here -1 indicates inf as we are not allowed to use INT_MAX
        qArray[i].distance = -1;
        pthArray[i].d = -1;
        pthArray[i].parent = 0;

    }

    // Relaxation of source element to 0
    decreaseKey(qArray,n,source-1, 0);

    int u, v, d;

    for(int j = n; j > 0; j--)
    {
        node = extractMin(qArray, j);
        u = node.vertex;

        pthArray[u-1].d = node.distance;

        temp = g[u-1].adjList;

        temp = temp->next;

        while(temp != NULL)
        {
            v = temp->v;


            for(int k = 0; k < j-1; k++)
            {
                if(qArray[k].vertex == v)
                {
                    d = qArray[k].distance;
                    pthArray[v-1].parent = u;
                    break;
                }
            }

            // relaxation if min path dist found
            if((node.distance + temp->weight) < d )
            {
                d = node.distance + temp->weight;
                decreaseKey(qArray, i-1, j, d);
            }


            temp = temp->next;
        }
    }

    return pthArray;
}


void printPath(struct pathNode *pth, int d)
{
    if(pth[d-1].parent == 0)
        return;

    printPath(pth, pth[d-1].parent );

    printf("%d ", d);

}

// Function to free the adjacency list of a Graph
void freeList(struct listNode *head)
{
    struct listnode *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }
}


// Free the graph
void freeGraph(struct Graph *g, int n)
{

    if(g == NULL)
    {
        return;
    }

    for(int i = 0; i < n; i++)
    {

        freeList(g[i].adjList);
    }

    g = NULL;

    return;
}


// allocates a new node with the value val and next pointer to be null
struct node *getNewNode(int val, int wt)
{
    struct listNode *newNode = (struct node *)malloc(sizeof(struct listNode));
    newNode->v = val;
    newNode->weight = wt;
    newNode->next = NULL;

    return newNode;
};


// inserts the edge to the list in a sorted manner
struct listNode* insertEdge(struct listNode* head, int value, int wt )
{
    struct listNode *newNode;
    newNode = getNewNode(value, wt);


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

// Utility functions to check if graph is properly implemented

void printGraph(struct Graph *g, int n)
{

    struct listNode *temp;

    for(int i =0; i < n; i++)
    {
        temp = (g[i]).adjList;
        while(temp != NULL)
        {
            printf(" (v = %d %d)", temp->v, temp->weight);
            temp = temp->next;
        }
        printf("\n");

    }
}


int getWeight(struct Graph *G, int n, int s, int e)
{
    struct listNode *temp;

    temp = (G[s]).adjList;

    while(temp != NULL)
    {
        //printf(" (v = %d %d)", temp->v, temp->weight);

        if(temp->v == e)
        {
            return temp->weight;
        }

        temp = temp->next;
    }

    return -1;


}

int main(){
  char choice;
  int numberOfVertices, startVertex, endVertex, wgt;
  int  source, dest;

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

       while(scanf("%d %d%c", &endVertex,&wgt, &delimiter)){

	 // Add the edge (startVertex, endVertex) to your graph here.

        adjList[startVertex] = insertEdge(adjList[startVertex], endVertex, wgt);

	 if(delimiter == '\n') break; // Detecting end of line.
       }
     }
     else if(choice == 'D')
     {

         scanf("%d %d", &source, &dest);

        for(int i = 0; i < numberOfVertices; i++)
        {
            myGraph[i] = adjList[i];
        }

        // printGraph(myGraph, numberOfVertices);

       // printf("%d \n", getWeight(myGraph, numberOfVertices, source,dest));
        // Call to the Dijkstra algorithm with source, dest and adjlist as parameters


        struct pathNode *path = (struct pathNode *)malloc(numberOfVertices *sizeof(struct pathNode));
        path = Dijkstra( myGraph,numberOfVertices, source );

        // print the path
        printPath(path, endVertex);
        printf("\n");

     }

     freeGraph(myGraph, numberOfVertices);

   }
   return(0);
}

