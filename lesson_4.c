/*lesson_4.c
* Home work. Dynamic programming.
*
*Chernenko Konstantin
*in CodeBlocks
*/

#include <stdio.h>
#include <stdlib.h>

#define X 8
#define Y 8
int board[Y][X];

void boardFillBarrier(int b) { // b - Максимальное число препятствий
  int i;
  int j;
  int k;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
      k = rand() % 2;
      if ((b != 0) && ( k> 0) ) {
         if ((i + j !=0) && (i + j != X+Y -2)) {
            board[i][j] = k;
            --b;
         }
      } else board[i][j] = 0;

	}
  }
}

void printBoard() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  printf("%3d", board[i][j]);
	}
	printf("\n");
  }
}

int routes(int x, int y) {
  if ((x == 0 || y == 0) )
	return board[x][y] == 0 ? 1 : 0;
  else
	return routes(x - 1, y) + routes(x, y - 1);
}

void fillArray(int* a, int len) {
  int i;
  for (i = 0; i < len; i++) {
	a[i] = rand() % 100;
  }
}

void printArray(int* a, int len) {
  int i;
  for (i = 0; i < len; i++) {
	printf("%d ", a[i]);
  }
  printf("\n");

}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSortimp(int* a, int len) {
  int i;
  int j;
  int flag;
  for (i = 0; i < len; i++) {
    flag = 0;
	for (j = 0; j < len - 1; j++) {
	  if (a[j] > a[j + 1]) {
        flag = 1;
		swap(&a[j], &a[j + 1]);
	  }
	}
    if (flag==0) break;
  }
}


int binSearch(int* a, int left, int right, int value) {

  if (left < right && a[(left + right) / 2] != value) {
    if (a[(left + right) / 2] < value) return binSearch(a, (left + right) / 2 + 1, right, value);
    else binSearch(a, left, (left + right) / 2, value);
  } else return (a[(left + right) / 2] == value) ? (left + right) / 2 : -1;

}



int main( )
{
    const int SIZE = 25;
    int arr[SIZE];

  // srand ( time(NULL) );
   boardFillBarrier(3);
   printBoard();
   printf("routes :%d\n\n", routes(X, Y));


   fillArray(arr, SIZE);


   bubbleSortimp(arr, SIZE);
   printArray(arr, SIZE);
   printf("binary %d search: %d\n\n\n", 56, binSearch(arr, 0, SIZE - 1, 56));






    return 0;
}

