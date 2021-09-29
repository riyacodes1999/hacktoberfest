#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ptr; 
    int sum; 

    int n;
    printf("Enter the no. of element: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", (ptr + i));
    }
    sum = 0; 
    for (int i = 0; i < n; i++) {
        sum += *(ptr + i);
    }
    printf("Sum of the elements: %d\n", sum);
    return 0;
}