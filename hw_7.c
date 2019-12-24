/*hw_7.c
* Home work. Graphs.
*
*Chernenko Konstantin
*in CodeBlocks
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct TNode
{
   struct GraphNode * Graph;
   int edgeWeight;
   struct TNode *next;
   struct TNode *prev;
} Node;
typedef struct
{
   Node *head;
   Node *tail;
   int size;
} List;

  List * listGr;

typedef struct GraphNode{
  int data;
  char index;
  int used;
  List* children;
} GraphNode;

void push(List *st, GraphNode * val) {

  Node *temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL) {
    printf("memory error");
    return;
  }
  temp->Graph = val;
  temp->next = st->head;
  temp->prev = NULL;
  if (st->head != NULL) st->head->prev = temp;

  st->head = temp;
  st->size++;
  if (st->size == 1) st->tail = temp;
  return;
}

GraphNode * popS(List *st) {
  if (st->size == 0) {
    printf("Stack error");
    return -1;
  }
  Node *temp = st->head;
  GraphNode *result = temp->Graph;

  st->head = st->head->next;
  if (st->size > 1) st->head->prev = NULL;
  st->size--;
  free(temp);
  return result;
}


GraphNode * popQ(List *st){
  if (st->size <= 0) {
    printf("list is empty");
    return -1;
  }
  Node *temp = st->tail;
  GraphNode *result = temp->Graph;
  st->tail = st->tail->prev;
  if (st->size > 1) st->tail->next = NULL;
  else st->head = NULL;

  st->size--;
  free(temp);
  return result;
}


GraphNode * getFromQueue(List * children, int i){
  GraphNode * result;
  Node * tmp;
  tmp = children->head;
  for (int z = 0; z < i; z++){
    tmp = tmp->next;
  }
  return tmp->Graph;

}

int widthTravers(GraphNode *start, GraphNode *stop) {
  List * queueGr;
  push(queueGr, start);
  start->used = 1;

  while (queueGr->size != 0) {
	GraphNode * current = popQ(queueGr);
	if (current->data = stop->data)
	  return current->data;
    int i = current->children->size;  // chtobi ne menyat' size v node
	while (i != 0) {
	  if (getFromQueue(current->children, i)->used != 1) {
		push(queueGr, getFromQueue(current->children, i));
		getFromQueue(current->children, i)->used = 1;
	  }
    i--;
	}
  }
  printf("data not found");
  return;
}

int getFromList(List * children, GraphNode * result){
  Node * tmp;
  tmp = children->head;
  for (int z = 0; z < children->size; z++){
    if (tmp->Graph->used == 0){
        tmp->Graph->used = 1;
        result = tmp->Graph;
        return 1;
      }
    tmp = tmp->next;
  }
  return 0;
}

int depthTravers(GraphNode *start, GraphNode *stop){
  push(listGr, start);
  GraphNode * current;
  start->used = 1;

  if (listGr->size != 0){
    if (start->data = stop->data) return stop->data;
    if (getFromList(start->children, &current)) {
      depthTravers(current, stop);
    }
    popS(listGr);
  }
}
int main()
{


    system("pause");
    return 0;
}

