#include <stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
int top=-1;
int disp(int s[]){
    int p=top;
    while(p--!=0){
        printf("%d ",s[p]);
    }
    printf("\n");
}
void quick_sort(int arr[], int left, int right, int size) {
    int stack[MAX_STACK_SIZE];
    stack[++top] = left;
    stack[++top] = right;
    int k=1;

    printf("Memory allocated for the array is [%d]\n",size);
    while (top >= 0) {
        printf("Contents of Stack in pass[%d]:::",k++);
        disp(stack);
        right = stack[top--];
        left = stack[top--];

        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++; j--;
            }
        }

        if (left < j) {
            stack[++top] = left;
            stack[++top] = j;
        }
        if (i < right) {
            stack[++top] = i;
            stack[++top] = right;
        }
    }
}
    int main() {
        int n;
        printf("Enter Array Size: ");
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
        quick_sort(a, 0, n - 1,n);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++){
            printf("%d ",a[i]);
        }
        printf("\n");

        return 0;

    }
