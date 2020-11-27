/*
Assignment 4
Roll Number: MS17BTECH11013
Name: PADIGAM PAVAN KALYAN

*/

#include<stdio.h>


// Maintain a array of structs to store the linked list


struct listNode {

	int v;
	struct listNode *next;

};

// for BFS we need this DS queue
struct Queue{
	int key;
	struct Queue *next;

	int front;
	int rear;


};


// insert at the end
struct Queue *enqueue(struct Queue *head, int a){
	struct Queue *temp = head;
	struct Queue *link = (struct Queue*)malloc(sizeof(struct Queue));
	link->key = a;
	link->next = NULL;

	if(temp == NULL)return link;

	while(temp->next != NULL) temp = temp->next;
	temp->next = link;
	return head;
}


struct node * getNewNode(int val)
{
    struct listNode *newNode = (struct node *)malloc(sizeof(struct listNode));
    newNode->v = val;
    newNode->next = NULL;

    return newNode;
};

struct list* insertEdge(struct listNode* head, int value)
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
void BFS(int n, struct list **Graph, int s, int *pi, int flag){
	int i=0,v,u, colors[n];
	// P.V = n;
	pi[0] = s;
	struct Queue *Q = NULL;
	for(i=0; i<n; i++){
		colors[i] = WHITE;
		pi[i+1] = 0;
	}
	colors[s-1] = GRAY;
	Q = enqueue(Q, s);
	while(Q != NULL){
		u = Q->key; // front
		if(flag == 0) printf("%d ", u);
		Q = dequeue(Q);
		struct list *adju = Graph[u-1];
		for(; adju != NULL; adju = adju->next){
			v = adju->v;
			if(colors[v-1] == WHITE){
				colors[v-1] = GRAY;
				pi[v] = u;
				Q = enqueue(Q, v);
			}
		}
		colors[u-1] = BLACK;
		// if(flag == 0) printf("%d ", u);
	}
}

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
void printGraph(struct list *head)
{
    struct listNode *temp = head;

    while(temp != NULL)
    {
        printf(" v = %d", temp->v);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
  char choice;
  int numberOfVertices, startVertex, endVertex;

  // Fetching number of vertices
  scanf("%d",&numberOfVertices);

  // Create your adjacency list's array of head vertices here.
 // struct graph *myGraph[numberOfVertices];

    // struct graph *myGraph = NULL;
    struct listNode *adjList[numberOfVertices];

    for(int i = 0; i < numberOfVertices; i++)
    {
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

        printf(" ( %d , %d ) edge and viceversa added", startVertex, endVertex);
        adjList[startVertex] = insertEdge(adjList[startVertex], endVertex);
        adjList[endVertex] = insertEdge(adjList[endVertex], startVertex);


     }

	 if(delimiter == '\n') break; // Detecting end of line.
       }
     }
     else if(choice == 'B'){
       scanf("%d",&startVertex);
       // Call BFS on your graph starting from startVertex here.
       for(int i = 0; i < numberOfVertices; i++)
       {
          // printf("Came till here\n");
           printGraph(adjList[i]);
       }
     }
   }
   return(0);
}
