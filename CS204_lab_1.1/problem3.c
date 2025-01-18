#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr[1024];

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_random_array(int* arr){
    srand(time(NULL));
    for(int i = 0; i < 1024; i++){
        arr[i] = rand();
    }
}

void bubbleSort(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    clock_t start, end_t;
    double cpu_time_used;

    start = clock();
    generate_random_array(arr);
    bubbleSort(arr, 1024);
    end_t = clock();

    cpu_time_used = ((double) (end_t - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}