/*lesson_3.c
* Home work. Search && Sort.
*
*Chernenko Konstantin
*in CodeBlocks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fillArray(int* a1, int* a2, int* a3, int len) {
  int i;

  for (i = 0; i < len; i++) {
	a1[i] = rand() % 100;
	a2[i] = a1[i];
	a3[i] = a1[i];
  }
}

void fillArray2(int* a1, int len) {
  int i;

  for (i = 0; i < len; i++) {
	a1[i] = rand() % 200 - 100;

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

// task 1 && 2
void bubbleSort(int* a, int len, int* count) {
  int i;
  int j;
  *count = 0;
  for (i = 0; i < len; i++) {
	for (j = 0; j < len - 1; j++) {
	  *count +=1;
	  if (a[j] > a[j + 1]) {
        swap(&a[j], &a[j + 1]);
	  }
	}
  }
}

void bubbleSortimp(int* a, int len, int *count) {
  int i;
  int j;
  int flag;
  *count = 0;
  for (i = 0; i < len; i++) {
    flag = 0;
	for (j = 0; j < len - 1; j++) {
      *count+=1;
	  if (a[j] > a[j + 1]) {
        flag = 1;
		swap(&a[j], &a[j + 1]);
	  }
	}
    if (flag==0) break;
  }
}

void sheikSort(int* a, int len, int *count)
{
  int i;
  int j;
  int revrs;
  int flag;
  *count = 0;
  for (i = 0; i < len; i++) {
    flag = 0;
    revrs = len-1;
	for (j = 0; j < len - 1; j++) {
      *count+=1;
	  if (a[j] > a[j + 1]) {
        flag = 1;
		swap(&a[j], &a[j + 1]);
	  }

      if (a[--revrs] > a[revrs+1]) {
        flag = 1;
		swap(&a[revrs], &a[revrs+1]);
	  }
	}
    if (flag==0) break;
  }


}

// task 4
int linearSearch(int* a, int len, int value)
{
    if (a[len] != value && len > 0)
        linearSearch(a, --len, value);
    else return (len == 0) ? -1 : len;
}

//  task 5
int pigeonhole(int* a, int len)
{
  int i;
  int j;
  int z=0;
  int tmp[200] = {0};
  for (i = 0; i < len; i++)
  {
     tmp[a[i]+100]++;
  }
  for (i = 0; i < 200; i++)
  {
     if (tmp[i] > 0)
     {
       for (j = 0; j < tmp[i]; j++) a[z++] = i-100;
     }
  }
}


int main( )
{
  const int SIZE = 25;
  int arr[SIZE];
  int arr2[SIZE];
  int arr3[SIZE];
  int count = 0;
//  srand ( time(NULL) );
  fillArray(arr, arr2, arr3, SIZE);
  printArray(arr, SIZE);
  bubbleSort(arr, SIZE, &count);
  printArray(arr, SIZE);
  printf("operations with standart bubblesort :%d\n", count);

  bubbleSortimp(arr2, SIZE, &count);
  printArray(arr2, SIZE);
  printf("operations with improved bubblesort:%d\n", count);

  printf("linear %d search: %d\n\n\n", 24, linearSearch(arr, SIZE, 24));

  printArray(arr3, SIZE);
  sheikSort(arr3, SIZE, &count);
  printArray(arr3, SIZE);
  printf("operations with sheikSort :%d\n\n\n", count);

  fillArray2(arr, SIZE);
  printArray(arr, SIZE);
  pigeonhole(arr, SIZE);
  printArray(arr, SIZE);
    return 0;
}

