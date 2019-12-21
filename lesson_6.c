/*lesson_6.c
* Home work. trees.
*
*Chernenko Konstantin
*in CodeBlocks
*/

#include <stdio.h>
#include <stdlib.h>
#define T int


typedef struct Node {
    char data;
    T index;
    struct Node *left;
    struct Node *right;
} Node;

Node * getFreeNode(T index, char ch){
  Node * tmp = (Node*)malloc(sizeof(Node));
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->index = index;
  tmp->data = ch;
  return tmp;
}

void symmetricTravers(Node *root) {
  if (root) {
	symmetricTravers(root->left);
	printf("index:%d, ", root->index);
	printf("char:%c |\n", root->data);
	symmetricTravers(root->right);
  }
}

void postorderTravers(Node *root) {
  if (root) {
	postorderTravers(root->left);
	postorderTravers(root->right);
	printf("index:%d, ", root->index);
	printf("char:%c |\n", root->data);
  }
}

void preOrderTravers(Node *root) {
  if (root) {
	printf("index:%d, ", root->index);
	printf("char:%c |\n", root->data);
	preOrderTravers(root->left);
	preOrderTravers(root->right);
  }
}

void insert(Node * *head, int n, char ch){
  if (*head == NULL) {
    *head = getFreeNode(n, ch);
    return;
  }
  Node * tmp = NULL;
  tmp = *head;
  while (tmp){
    if (n > tmp->index) {
      if (tmp->right) {
        tmp = tmp->right;
        continue;
      } else {
          tmp->right = getFreeNode(n, ch);
          return;
      }
    } else if (n < tmp->index){
        if (tmp->left) {
          tmp = tmp->left;
          continue;
          } else {
          tmp->left = getFreeNode(n, ch);
          return;
          }
      } else {
          printf("Error building tree");
          return;
       }
  }
}

char findChar(Node * head, int n){
  if (head == NULL) {
    printf("Tree is empty");
    return;
  }
  if (n == head->index) return head->data;
  if ((n > head->index) && (head->right)) return findChar(head->right, n);
  if ((n < head->index) && (head->left)) return findChar(head->left, n);
}

int hash(char str[]){
  int i = 0;
  int result = 0;
  while (str[i]){
    result += str[i++];
  }
  return result;
}

int main(){
  int index[10] = {5,8,4,3,9,7,6,2,0,1};
  char data[10] = {'f','i','e','d','j','h','g','c','a','b'};
  Node * tree = NULL;
  for (int i=0; i<10; i++) {
    insert(&tree, index[i], data[i]);

  }
  printf("preorderTravers:\n");
  preOrderTravers(tree);
  printf("symmetricTravers:\n");
  symmetricTravers(tree);
  printf("PostorderTravers:\n");
  postorderTravers(tree);
  printf("Search in tree with index 7, result:%c", findChar(tree, 7));
  printf("Sum of character codes \"Hello world!\" =%d", hash("Hello world!"));
  return 0;
}
