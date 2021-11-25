#include<stdio.h>
#include<stdlib.h>
#include <time.h> 

#define MAX_ARRAY 300

//global variable for arrayLength
int n;
//global variables for all sort timings
double bubbleSortTime;
double quickSortTime;
double selectionSortTime;
double insertionSortTime;
double mergeSortTime;

//Csv file reading and loading into an array
int *getDatafromCSV(int *array){
    FILE *fp;
    fp = fopen("numbers.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 0;
    }
    int totalCount = 50;
    int i;
    for(i=0;i<totalCount;i++){
        fscanf(fp, "%d", &array[i]);
    }
    fclose(fp);
    return array;

}
//CSV file program ends


void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//BubbleSort related functions start
void swap(int *xp, int *yp)
{
    //swapping of twom numbers using a third pointer variable
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[],int n){
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    //operation of bubble sort starts here
    int i, j;
    for (i = 0; i < n-1; i++){
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
               swap(&arr[j], &arr[j+1]);
           }  
        } 
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    bubbleSortTime = time_spent;
    printf("Sorted array is: \n");
    printArray(arr, n);

}

int bubbleSortDriver(){
    int *arr;
    int array[MAX_ARRAY];
    arr = getDatafromCSV(array);
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}
//BubbleSort related functions end

//QuickSort related functions start
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}

int quickSortDriver(){
    int *arr;
    int array[MAX_ARRAY];
    arr = getDatafromCSV(array);
    int n = sizeof(arr) / sizeof(arr[0]);

    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    quickSortTime = time_spent;
    // printf("The elapsed time for QuickSort is %f seconds\n", quickSortTime);
    // printf("Sorted array (QuickSort applied): \n");
    // printArray(arr, n);
    return 0;
}
//QuickSort related functions end

//SelectionSort Related Function Starts
void selectionSort(int arr[], int n)
{   
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    insertionSortTime = time_spent;
    // printf("The elapsed time for selectionsort is %f seconds\n", insertionSortTime);
    // printf("Sorted array (SelectionSort applied): \n");
    // printArray(arr, n);
}

int selectionSortDriver(){
    int *arr;
    int array[MAX_ARRAY];
    arr = getDatafromCSV(array);
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    return 0;
}
//SelectionSort Related Function End

//InsertionSort Related Functions Start
void insertionSort(int arr[], int n)
{
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    selectionSortTime = time_spent;
    // printf("The elapsed time for Insertionsort is %f seconds\n", selectionSortTime);
    // printf("Sorted array (InsertionSort applied): \n");
    // printArray(arr, n);
}

int insertionSortDriver(){
    int *arr;
    int array[MAX_ARRAY];
    arr = getDatafromCSV(array);
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    return 0;
}
//InsertionSort Related Functions End

//MergeSort Related function Start
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int mergeSortDriver()
{
    int *arr;
    int array[MAX_ARRAY];
    arr = getDatafromCSV(array);
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    mergeSort(arr, 0, arr_size - 1);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    mergeSortTime = time_spent;
    // printf("Sorted array (MergeSort applied): \n");
    // printArray(arr, n);
    return 0;
}
//MergeSort Related Function End

//Console Reporting Template Start
int printSingleResult(){
    printf("--------------------------------------------------------------------\n");
    printf("| Sorting Algorithm Used       |      Time Elapsed (in seconds)    |\n");
    printf("--------------------------------------------------------------------\n");
    printf("| %s                                    %lf                            \n","BubbleSort",bubbleSortTime);
    printf("| %s                                     %lf                            \n","QuickSort",quickSortTime);
    printf("| %s                                 %lf                            \n","SelectionSort",selectionSortTime);
    printf("| %s                                 %lf                            \n","InsertionSort",insertionSortTime);
    printf("| %s                                     %lf                            \n","MergeSort",mergeSortTime);
    printf("--------------------------------------------------------------------\n");

    //Reporting Part Start
    //sorting_report.csv
    FILE *fs;
    fs = fopen("sorting_report.csv", "a");
    if(fs == NULL){
      printf("Couldn't open file\n");
      return 0;
    }
    fprintf(fs, "%d,%s,%lf\n",n,"BubbleSort",bubbleSortTime);
    fprintf(fs, "%d,%s,%lf\n",n,"QuickSort",quickSortTime);
    fprintf(fs, "%d,%s,%lf\n",n,"SelectionSort",selectionSortTime);
    fprintf(fs, "%d,%s,%lf\n",n,"InsertionSort",insertionSortTime);
    fprintf(fs, "%d,%s,%lf\n",n,"MergeSort",mergeSortTime);
    //Reporting Part End
    return 0;

}
//Console Reporting Template End


int main(){

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    n = sizeof(arr)/sizeof(arr[0]);
    bubbleSortDriver();
    quickSortDriver();
    selectionSortDriver();
    insertionSortDriver();
    mergeSortDriver();
    printSingleResult();
    return 0;
}