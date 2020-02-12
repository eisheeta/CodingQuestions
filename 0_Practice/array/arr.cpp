#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//check if array is mirror inverse
bool isMirrorInverse(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++)  
    { 
        if (arr[arr[i]] != i) 
            return false; 
    } 
  
    return true; 
} 

//print mirror inverse of array
void rev(int arr[], int n){
    int rev[n];
    for(int i=0; i<n; i++){
            rev[arr[i]] =i;     
        }
    
    for(int i=0; i<n; i++){
        cout<<rev[i]<<" ";
    }
    cout<<endl;
}


//sorting
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)       
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])  
                swap(&arr[j], &arr[j+1]);  
}  
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        
        while (j >= 0 && arr[j] < key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
        
    for (i = 0; i < n-1; i++)  
    {  
        
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
   
        swap(&arr[min_idx], &arr[i]);  
    }  
}  

//...................................................................................
//print an array
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    // cout<<isMirrorInverse(arr,n)<<endl;
    // rev(arr, n);
    //bubbleSort(arr, n);
    //insertionSort(arr, n);
    //selectionSort(arr, n);
    
    printArray(arr, n);
    
    
    return 0;
}
