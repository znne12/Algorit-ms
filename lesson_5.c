/*lesson_5.c
* Home work. Dynamic data.
*
*Chernenko Konstantin
*in CodeBlocks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T char

struct TNode
{
   T value;
   struct TNode *next;
   struct TNode *prev;
};
typedef struct TNode Node;
typedef struct
{
   Node *head;
   Node *tail;
   int size;
   int maxSize;
} List;
    List parenthesis;
    List squareBrackets;
    List curlyBrace;
    List doublyList;
    List tmp2;
    int popError = 0;

int push(List *st, T val) {
  if (st->size >= st->maxSize) {
     printf("Error stack size ");
     return -1;
  }

  Node *temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL) return 0;

  temp->value = val;
  temp->next = st->head;
  temp->prev = NULL;
  if (st->head != NULL) st->head->prev = temp;

  st->head = temp;
  st->size++;
  if (st->size == 1) st->tail = temp;
  return 1;
}

T pop(List *st, int *popError) {
  if (st->size == 0) {
    popError = -1;
    return;
  }
  Node *temp = st->head;
  T result = temp->value;

  st->head = st->head->next;
  st->size--;
  free(temp);
  return result;
}

// Task 4
T popList(List *st, int *popError){
  if (st->size == 0) {
    popError = -1;
    return;
  }
  Node *temp = st->tail;
  T result = temp->value;

  st->tail = st->tail->prev;
  st->size--;
  free(temp);
  return result;
}

//  task 1
int decTobin(int dec, char * out)
{
    int j = 0;
    if (dec <= 0) return -1;
    while (dec != 0)
    {
        if (dec % 2 == 0) push(&parenthesis, '0');
        else push(&parenthesis, '1');
        dec >>= 1;
        j++;
    }
    for (int i = 0; i < j; i++)
    {
        out[i] = pop(&parenthesis, 0);
    }
    return 1;
}

//  Task 2
int testBrackets(char* in){
    int popError = 0;
    for (int i = 0; i < strlen(in); i++){
        switch (in[i]){
        case '(':
            if (push(&parenthesis, '1') == 1){
                break;
            } else return -1;
         case '[':
            if (push(&squareBrackets, '1') == 1){
                break;
            } else return -1;
         case '{':
            if (push(&curlyBrace, '1') == 1){
                break;
            } else return -1;
         case ')':
            if (pop(&parenthesis, popError) == '1'){
                break;
            } else if (popError = -1)return 1;
         case ']':
            if (pop(&squareBrackets, popError) == '1'){
                break;
            } else if (popError = -1)return 1;
         case '}':
            if (pop(&curlyBrace, popError) == '1'){
                break;
            } else if (popError = -1)return 1;
        }
    }
    if (parenthesis.size > 0 || squareBrackets.size > 0 || curlyBrace.size > 0) return 1;
    return 0;
}

void PrintStack(List * st)
{
    List *st1 = st;
    while(st1->head != NULL)
    {
        printf("%c ", st1->head->value);
        st1->head = st1->head->next;
    }
}

// Task 3
void copyList(List *st1, List *st2){
    if (st2->head != NULL) {
        printf("Second list must be empty!");
        return;
    }
    List * tmp1 = st1;
     while(tmp1->tail != NULL)
    {
        push(&tmp2, tmp1->tail->value);
        tmp1->tail = tmp1->tail->prev;
    }
    *st2 = tmp2;
}

int main()
{
    parenthesis.maxSize = 100;
    curlyBrace.maxSize = 100;
    squareBrackets.maxSize = 100;
    doublyList.maxSize = 100;
    tmp2.maxSize = 100;
    // task 1
    int dec;
    char out[64] = {0};
    printf("Input decimal number:");
    scanf("%d", &dec);
    decTobin(dec, out);
    printf("%s %s\n\n\n",decTobin(dec, out) == 1 ? "Binary:" : "Error!", out);
// task 2
    char in[256];
    printf("Enter an example with parentheses:");
    scanf("%s", &in);
    switch (testBrackets(&in)){
        case 0:
           printf("No errors\n");
        break;
        case -1:
           printf("Not enough memory || out of stack!\n");
        break;
        case 1:
           printf("Error!\n");
        break;
        }
// task 3
    push(&parenthesis, 'a');
    push(&parenthesis, 'b');
    push(&parenthesis, 'd');
    push(&parenthesis, 'q');
    copyList(&parenthesis, &curlyBrace);
    printf("Primary list:");
    PrintStack(&parenthesis);
    printf("\n");

    printf("Copied list:");
    PrintStack(&curlyBrace);
    printf("\n");
 // task 4
    push(&doublyList, 'a');
    push(&doublyList, 'b');
    push(&doublyList, 'c');
    push(&doublyList, 'd');
    push(&doublyList, '2');
    push(&doublyList, '4');
    printf("Doubly linked list:\n");
    PrintStack(&doublyList);
    printf("\n");

    while (doublyList.size > 0)
        printf("%c ", popList(&doublyList, popError));

    return 0;
}

