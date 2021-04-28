#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//Global Variable for time counting purpose;
double linearSearchTime;
double binarySearchTime;

//Linear Search Functions Start
int linearSearch(int arr[], int n, int x)
{
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    int result = -1;

    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x){
            result = i;
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    linearSearchTime = time_spent;
    return result;
}

int linearSearchDriver()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 50;
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    int result = linearSearch(arr, n, x);
    (result == -1)
        ? printf("Element is not present in array (using Linear Search)\n")
        : printf("Element is present at index %d (using Linear Search)\n", result);
    
    return 0;
}
 
// Linear Search Functions End

//Binary Search Function Start
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int binarySearchDriver()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();
    int result = binarySearch(arr, 0, n - 1, x);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    binarySearchTime = time_spent;

    (result == -1) ? printf("Element is not present in array (using Binary Search)\n")
                   : printf("Element is present at index %d (using Binary Search)\n",result);
    return 0;
}
//binary Search Function End

//Final Reporting Start
int printSingleResult(){
    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("| Sorting Algorithm Used       |      Time Elapsed (in seconds)    |\n");
    printf("--------------------------------------------------------------------\n");
    printf("| %s                                    %lf                            \n","Linear Search",linearSearchTime);
    printf("| %s                                    %lf                            \n","Binary Search",binarySearchTime);
    printf("--------------------------------------------------------------------\n");
    return 0;

}
// Final Reporting End

int main(){
    linearSearchDriver();
    binarySearchDriver();
    printSingleResult();
    return 0;
}